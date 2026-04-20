/*
 * _coder_map_predict_info.c
 *
 * Code generation for function 'map_predict'
 *
 */

/* Include files */
#include "_coder_map_predict_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789cc5535b4ec250103d18242606c5c4b80b899018a37f082a442a25800911034d7bb10d"
      "f4913e4cfd73072ec00df8e1876b70052ec0c5382d2d8f264d89449c"
      "a4f7ccf4cccc99de7b8b548d4b01d8c1c4de3213cc06712ec00d2c5a944fc560689b482f"
      "d485fc4b80a2aed9ccb5278126a86c5a29e9aaa2099add7e32184c66",
      "e9e34726f9cc5019b3b6a2b2d67c70e345eae51c350d3ccaf3cb3213472d4785295bb309"
      "c7f3c1743f0631df9b4ed88fa845f7239a17ea19bfd40bfb6f27e885"
      "bc2a187dc3649222da0bfa8315f533b1fa13c6b24dc7930cf58e52abe9c9317a7b017e05"
      "78870bdca38c33f4d08105ba4ab4f670459e469e0c85308f3a4ae0d1",
      "4683d6435c9357c009aa28e21835caaf50be85116ce874565e3d47793c65547ce4a8be43"
      "5ecbefe4718587f6f36b33dbfdb0aa66727ecfefac63ec4fa7422095"
      "3e3d26e94a34a3487c9ede279dd7ee92fb17f7bf66b1e5a3fbf9ed53ebd27b1f0ef7d7a9"
      "17da7fe9b931fd96bdff07317ab908df1d99b776b3eb3a0ed76af0f5",
      "62e9b47e5e2ccfe6e0137492e6404cfcd7fd7f00c371660c", ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1728U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("map_predict"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
          "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
          "\x88\\GM-PHD-PMAU-SLAM\\tools\\map_predict.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740074.67349537031));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2943329 (R2025a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("HsMzipMF8AuyNDXHK3RVpF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_map_predict_info.c) */
