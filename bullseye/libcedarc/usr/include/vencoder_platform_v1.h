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


#ifndef _VENCODER_EXT_V1_H
#define _VENCODER_EXT_V1_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define WATERMARK_MAX_NUM     (5)
#define WATERMARK_CONTEXT_LEN (23)
#define ICON_PIC_PATH_MAX_LEN (64)

typedef struct VencWatermarkItemS {
    unsigned int start_pos_x;
    unsigned int start_pos_y;
    unsigned char context[WATERMARK_CONTEXT_LEN];
}VencWatermarkItemS;

typedef struct VencWatermarkInfoS {
    unsigned int       item_num;
    VencWatermarkItemS item[WATERMARK_MAX_NUM];
    unsigned char      icon_pic_path[ICON_PIC_PATH_MAX_LEN];
}VencWatermarkInfoS;

typedef struct {
    unsigned int sum_mad;
    unsigned int sum_qp;
    unsigned long long sum_sse;
    unsigned int avg_sse;
}VencMBSumInfo;

typedef enum VENC_INDEXTYPE_PLATFORM_V1 {

    VENC_IndexParam_PlatformV1_Start = 0x2f000000,

    /**< reference type: VencWatermarkInfoS */
    VENC_IndexParamSetOverlayByWatermark,

}VENC_INDEXTYPE_PLATFORM_V1;


#ifdef __cplusplus
}
#endif

#endif

