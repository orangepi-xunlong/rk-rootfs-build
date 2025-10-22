/*
* Copyright (c) 2008-2016 Allwinner Technology Co. Ltd.
* All rights reserved.
*
* File : ve_interface_ext.h
* Description :
* History :
*   Author  : xyliu <xyliu@allwinnertech.com>
*   Date    : 2016/04/13
*   Comment :
*
*
*/


#ifndef _VENCODER_EXT_V2_H
#define _VENCODER_EXT_V2_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_RC_GOP_SIZE                   256

typedef struct VencBinImageParam {
	unsigned int enable;
	unsigned int moving_th;//range[1,31], 1:all frames are moving,
                           //            31:have no moving frame, default: 20
}VencBinImageParam;

typedef struct VencGetBinImageBufInfo {
	unsigned int   max_size;
	unsigned char* buf;
}VencGetBinImageBufInfo;

typedef struct VencGetMvInfoBufInfo {
	unsigned int   max_size;
	unsigned char* buf;
}VencGetMvInfoBufInfo;

typedef struct VencEnvLvRange {
    int env_lv_high_th;
    int env_lv_low_th;
    int env_lv_coef;  //range[0,15]
}VencEnvLvRange;

typedef enum {
    VENC_ST_DIS_WDR      = 0,
    VENC_ST_EN_WDR       = 1,
    VENC_ST_NONE
}eSensorType;

typedef union {
    unsigned char val;
    struct {
        unsigned char qp    : 6;
        unsigned char skip  : 1;
        unsigned char en    : 1;
    }reg;
}uMbQpMap;

typedef union {
    unsigned int val;
    uMbQpMap     mb[4];
}uCtuQpMap;

typedef struct {
    unsigned int  sad_th;
    unsigned int  sad_num;
    int           hor_expand;
    int           ver_expand;

    unsigned int  mse_th[4];
    int           mse_qp[5];
    int           max_mse_qp;
    int           min_mse_qp;

    float         force_qp_ratio_th0;
    float         force_qp_ratio_th1;
}sQpMapPara;

typedef struct {
    unsigned int is_move    : 1;
    unsigned int is_expand  : 1;
    unsigned int en_mad     : 1;
    unsigned int r0         : 5;
    unsigned int mad_val    : 8;
    unsigned int mse_val    : 16;
}sCtuQpInfo;

typedef struct {
    // all these average value is for mb16x16
    unsigned int avg_mad;
    unsigned int avg_sse;
    unsigned int avg_qp;
    double avg_psnr;
}VencMBSumInfo_V2;

typedef struct {
    int pix_x_bgn;
    int pix_x_end;
    int pix_y_bgn;
    int pix_y_end;
    int total_num;
    int intra_num;
    int large_mv_num;
    int small_mv_num;
    int zero_mv_num;
    int large_sad_num;
    int is_motion;
}VencMotionSearchRegion;

typedef struct {
    int en_motion_search;
    int dis_default_para;
    int large_mv_th;
    int least_motion_region_num;
    int dis_search_region[50];
    float large_mv_th_coef;
    float large_mv_ratio_th;    // include intra and large mv
    float non_zero_mv_ratio_th; // include intra, large mv and samll mv
    float large_sad_ratio_th;
}VencMotionSearchParam;

typedef struct {
    int region_hgt;
    int ex_row_hgt;
    int region_wth;
    int ex_col_wth;
    int motion_rengion_num;
    VencMotionSearchParam param;
    VencMotionSearchRegion region[50];
}VencMotionSearch;

typedef enum eWARPTYPE
{

    Warp_LDC,

    Warp_LDC_Pro,

    Warp_Pano180,

    Warp_Pano360,

    Warp_Normal,

    Warp_Fish2Wide,

    Warp_Perspective,

    Warp_BirdsEye,

    Warp_User
} eWarpType;

typedef struct {
	char  src_file[256];
	char  dst_file[256];
//Top
	int img_format;
	int yuv_dns_en;
	int frame_num;
	int input_width;
	int input_height;
	int output_width;
	int output_height;
	int bTop_en;
	int rotAngle;
	int bMirror;
	int bLBC_en;
	int bSC_en;
	int bCrop_en;
	int crop_x;
	int crop_y;
	int crop_width;
	int crop_height;
//GDC
	int bGDC_en;
	int bByPass;
	int warpMode;
	int mountMode;
	int calib_pic_w;
	int calib_pic_h;
	float fx;
	float fy;
	float cx;
	float cy;
	float fx_scale;
	float fy_scale;
	float cx_scale;
	float cy_scale;
	char path_lut_ldc_pro[256];
	int  eLensDistModel;
	float distCoef_wide_ra[3];
	float distCoef_wide_ta[2];
	float distCoef_fish_k[4];
	int centerOffsetX;
	int centerOffsetY;
	int rotateAngle;
	int radialDistortCoef;
	int trapezoidDistortCoef;
	int fanDistortCoef;
	int pan;
	int tilt;
	int zoomH;
	int zoomV;
	int scale;
	int innerRadius;
	float roll;
	float pitch;
	float yaw;
	int perspFunc;
	float perspectiveProjMat[9];
	char  birds_file[256];
	int birdsImg_width;
	int birdsImg_height;
	float mountHeight;
	float roiDist_ahead;
	float roiDist_left;
	float roiDist_right;
	float roiDist_bottom;
//Adscaler
	int peaking_en;
	int peaking_clamp;
	int peak_m;
	int th_strong_edge;
	int peak_weights_strength;

//debug
	int blk_format;//0=16x16,1=32x32,2=16x8,3=8x8
	//for user mode
	short *lut_x;
	short *lut_y;
}sInputPara;

typedef enum eMOUNTTYPE
{

	Mount_Top,

	Mount_Wall,

	Mount_Bottom
}eMountType;

typedef enum eLENSDISTMODEL
{
	DistModel_WideAngle,
	DistModel_FishEye
}eLensDistModel;

typedef enum  ePERSPFUNC
{
	Persp_Only,
	Persp_LDC
}ePerspFunc;

typedef enum VENC_INDEXTYPE_PLATFORM_V2 {

    VENC_IndexParam_PlatformV2_Start = 0x3f000000,

    /**< reference type: VencMBSumInfo_V2 */
    VENC_IndexParamMBSumInfoOutput_V2,

    /**< reference type: unsigned int; 0: sp2305 1: c2398*/
    VENC_IndexParamSensorType,

    /**< reference type: VencBinImageParam */
    VENC_IndexParamEnableGetBinImage,

    /**< reference type: unsigned char* */
    VENC_IndexParamGetBinImageData,

    /**< reference type: unsigned int; 0: disable, 1: enable*/
    VENC_IndexParamEnableMvInfo,

    /**< reference type: unsigned char* */
    VENC_IndexParamGetMvInfoData,

    /**< reference type: unsigned int */
    VENC_IndexParamSetLVAdjTh,

    /**< reference type: VencEnvLvRange */
    VENC_IndexParamSetEnvLvTh,

    /**< reference type: VencVbrParam */
    VENC_IndexParamSetVbrParam,

    /**< reference type: Set or Get VencMotionSearchParam* */
    VENC_IndexParamMotionSearchParam,

    /**< reference type: Get VencMotionSearchRegin* */
    VENC_IndexParamMotionSearchResult,

    /**< reference type: TEST WB YUV* */
    VENC_IndexParamWbYuv,

    /**< reference type: sGdcParam*/
    VENC_IndexParamGdcConfig,
    /**< reference type: sGdcParam*/
    VENC_IndexParamHwCropConfig,

}VENC_INDEXTYPE_PLATFORM_V2;

#ifdef __cplusplus
}
#endif

#endif

