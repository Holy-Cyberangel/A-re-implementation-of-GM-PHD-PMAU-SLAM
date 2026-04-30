function build_core_mex()
%BUILD_CORE_MEX Build the single-step GM-PHD core as a MATLAB MEX file.

    rootDir = fileparts(mfilename('fullpath'));
    toolsDir = fullfile(rootDir, 'tools');
    dataDir = fullfile(rootDir, 'data');
    buildDir = fullfile(rootDir, 'codegen', 'slam_step_mex');

    addpath(toolsDir);
    addpath(dataDir);

    loaded = load(fullfile(dataDir, 'Configration.mat'), 'params');
    params = loaded.params;

    measFile = fullfile(dataDir, 'Measurement.mat');
    maxZ = 48;
    if exist(measFile, 'file') == 2
        loadedMeas = load(measFile, 'Measurement');
        if isfield(loadedMeas, 'Measurement') && ~isempty(loadedMeas.Measurement)
            maxZ = max(maxZ, max(cellfun(@(z) size(z, 2), loadedMeas.Measurement(:))));
        end
    end
    maxMap = max(512, params.max_components + maxZ + 64);

    xType = coder.typeof(zeros(3,1));
    PType = coder.typeof(zeros(3,3));
    odomType = coder.typeof(zeros(2,1));
    meaType = coder.typeof(zeros(2,1), [2 maxZ], [0 1]);
    mapType = coder.typeof(local_map_template(), [1 maxMap], [0 1]);
    flagType = coder.typeof(false);

    cfg = coder.config('mex');

    oldDir = cd(toolsDir);
    cleanup = onCleanup(@() cd(oldDir)); %#ok<NASGU>

    if exist(buildDir, 'dir') ~= 7
        mkdir(buildDir);
    end

    codegen('-config', cfg, 'slam_step_codegen.m', ...
        '-args', {xType, PType, odomType, meaType, mapType, params, coder.typeof(0), flagType}, ...
        '-o', 'slam_step_mex', ...
        '-d', buildDir);

    fprintf('Built MEX: %s\n', fullfile(toolsDir, ['slam_step_mex.' mexext]));
end

function mapItem = local_map_template()
    mapItem = struct('m', zeros(2,1), 'w', 0, 'P', zeros(2,2), 'label', zeros(2,1));
end
