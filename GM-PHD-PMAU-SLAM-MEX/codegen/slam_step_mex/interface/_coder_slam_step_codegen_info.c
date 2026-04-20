/*
 * _coder_slam_step_codegen_info.c
 *
 * Code generation for function 'slam_step_codegen'
 *
 */

/* Include files */
#include "_coder_slam_step_codegen_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789cc5545b4ec250103d3548fc41f1c75d48c4c418fd1241a4d12a869248c44053aeb4d2"
      "07e116c53f77e002dc841f24feba0337c006dc85d396f268d2d448c4"
      "f9b867266766cedce90382280900d6e1db47d2c7d4384e8f7105f316e685080c6c1589b9"
      "ba807f19a36a5b0e1b387e6029269b54b66c53b714cb919fba0c3dc6",
      "6de381b53ce64e3798ac9bac321b5cb891599ca126814bb97e5e636aa7d237d1d3f87442"
      "633698eca31971df44cc3ec216de47382fd01bfc522fe8bf19a317f0"
      "dc50cc067758b7a1da2dd66656688ee682732423e7f019eef4faaa33d53b1216d3b34271"
      "60c17d4763bcc1096e91c721eaa882835e293aeb3825cf224f834e98",
      "c139722843c6259ddb38232f8b7d94b08b3d88945fa07c8e0e1cd8e87af512e59529a3e0"
      "a144f555f22a5e2797cbb6e5e7d7ab54ed8d977af1f975afb30dc39b"
      "8e132a30d120cf21e52e792ab12df2dbdee419625d8b7b7e1b3fdc67d4779cc29a87ef9f"
      "2361997af2f06bb84cbdc0fe4b6fd1ffc056845e3ac48b55f931b753",
      "cc1f48594d14f5fbda75c7281d4fe728c7e8c4cd8188f8affb7f0358d06c5a", ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1752U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("slam_step_codegen"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\Genshin.LAPTOP-KT17H25I\\Desktop\\GM-PHD-PMAU-SLAM-"
          "\xe6\x9c\xb1\xe8\x81\x94\xe5\x86\x9b\xe5\xa4\x8d\xe7\x8e\xb0\xe7\x89"
          "\x88\\GM-PHD-PMAU-SLAM\\tools\\slam_step_codegen.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740091.53336805559));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2943329 (R2025a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("wW38FJDh5HoZvKLrG0hwiG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_slam_step_codegen_info.c) */
