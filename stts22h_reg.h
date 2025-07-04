/**
  ******************************************************************************
  * @file    stts22h_reg.h
  * @author  Sensors Software Solution Team
  * @brief   This file contains all the functions prototypes for the
  *          stts22h_reg.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STTS22H_REGS_H
#define STTS22H_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

/** @addtogroup STTS22H
  * @{
  *
  */

/** @defgroup  Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/**
  * @}
  *
  */

/** @defgroup STMicroelectronics sensors common types
  * @{
  *
  */

#ifndef MEMS_SHARED_TYPES
#define MEMS_SHARED_TYPES

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0       : 1;
  uint8_t bit1       : 1;
  uint8_t bit2       : 1;
  uint8_t bit3       : 1;
  uint8_t bit4       : 1;
  uint8_t bit5       : 1;
  uint8_t bit6       : 1;
  uint8_t bit7       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7       : 1;
  uint8_t bit6       : 1;
  uint8_t bit5       : 1;
  uint8_t bit4       : 1;
  uint8_t bit3       : 1;
  uint8_t bit2       : 1;
  uint8_t bit1       : 1;
  uint8_t bit0       : 1;
#endif /* DRV_BYTE_ORDER */
} bitwise_t;

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, const uint8_t *, uint16_t);
typedef int32_t (*stmdev_read_ptr)(void *, uint8_t, uint8_t *, uint16_t);
typedef void (*stmdev_mdelay_ptr)(uint32_t millisec);

typedef struct
{
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Component optional fields **/
  stmdev_mdelay_ptr   mdelay;
  /** Customizable optional pointer **/
  void *handle;

  /** private data **/
  void *priv_data;
} stmdev_ctx_t;

/**
  * @}
  *
  */

#endif /* MEMS_SHARED_TYPES */

/**
  * @}
  *
  */

/** @defgroup STTS22H_Infos
  * @{
  *
  */

/** I2C Device Address 8 bit format **/
#define STTS22H_I2C_ADD_H       0x71U
#define STTS22H_I2C_ADD_L       0x7FU

/** Device Identification (Who am I) **/
#define STTS22H_ID              0xA0U

/**
  * @}
  *
  */

#define STTS22H_WHOAMI                       0x01U
#define STTS22H_TEMP_H_LIMIT                 0x02U
typedef struct
{
  uint8_t thl                 : 8;
} stts22h_temp_h_limit_t;

#define STTS22H_TEMP_L_LIMIT                 0x03U
typedef struct
{
  uint8_t tll                 : 8;
} stts22h_temp_l_limit_t;

#define STTS22H_CTRL                         0x04U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t one_shot            : 1;
  uint8_t time_out_dis        : 1;
  uint8_t freerun             : 1;
  uint8_t if_add_inc          : 1;
  uint8_t avg                 : 2;
  uint8_t bdu                 : 1;
  uint8_t low_odr_start       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t low_odr_start       : 1;
  uint8_t bdu                 : 1;
  uint8_t avg                 : 2;
  uint8_t if_add_inc          : 1;
  uint8_t freerun             : 1;
  uint8_t time_out_dis        : 1;
  uint8_t one_shot            : 1;
#endif /* DRV_BYTE_ORDER */
} stts22h_ctrl_t;

#define STTS22H_STATUS                       0x05U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t busy                : 1;
  uint8_t over_thh            : 1;
  uint8_t under_thl           : 1;
  uint8_t not_used_01         : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01         : 5;
  uint8_t under_thl           : 1;
  uint8_t over_thh            : 1;
  uint8_t busy                : 1;
#endif /* DRV_BYTE_ORDER */
} stts22h_status_t;

#define STTS22H_TEMP_L_OUT                   0x06U
#define STTS22H_TEMP_H_OUT                   0x07U

#ifndef __weak
#define __weak __attribute__((weak))
#endif /* __weak */

/*
 * These are the basic platform dependent I/O routines to read
 * and write device registers connected on a standard bus.
 * The driver keeps offering a default implementation based on function
 * pointers to read/write routines for backward compatibility.
 * The __weak directive allows the final application to overwrite
 * them with a custom implementation.
 */

int32_t stts22h_read_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                         uint8_t *data,
                         uint16_t len);
int32_t stts22h_write_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                          const uint8_t *data,
                          uint16_t len);

float_t stts22h_from_lsb_to_celsius(int16_t lsb);

typedef enum
{
  STTS22H_POWER_DOWN   = 0x00,
  STTS22H_ONE_SHOT     = 0x01,
  STTS22H_1Hz          = 0x04,
  STTS22H_25Hz         = 0x02,
  STTS22H_50Hz         = 0x12,
  STTS22H_100Hz        = 0x22,
  STTS22H_200Hz        = 0x32,
} stts22h_odr_temp_t;
int32_t stts22h_temp_data_rate_set(const stmdev_ctx_t *ctx,
                                   stts22h_odr_temp_t val);
int32_t stts22h_temp_data_rate_get(const stmdev_ctx_t *ctx,
                                   stts22h_odr_temp_t *val);

int32_t stts22h_block_data_update_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t stts22h_block_data_update_get(const stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t stts22h_temp_flag_data_ready_get(const stmdev_ctx_t *ctx,
                                         uint8_t *val);

int32_t stts22h_temperature_raw_get(const stmdev_ctx_t *ctx, int16_t *val);

int32_t stts22h_dev_id_get(const stmdev_ctx_t *ctx, uint8_t *buff);

typedef struct
{
  uint8_t busy             : 1;
} stts22h_dev_status_t;
int32_t stts22h_dev_status_get(const stmdev_ctx_t *ctx,
                               stts22h_dev_status_t *val);

typedef enum
{
  STTS22H_SMBUS_TIMEOUT_ENABLE    = 0,
  STTS22H_SMBUS_TIMEOUT_DISABLE   = 1,
} stts22h_smbus_md_t;
int32_t stts22h_smbus_interface_set(const stmdev_ctx_t *ctx,
                                    stts22h_smbus_md_t val);
int32_t stts22h_smbus_interface_get(const stmdev_ctx_t *ctx,
                                    stts22h_smbus_md_t *val);

int32_t stts22h_auto_increment_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t stts22h_auto_increment_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t stts22h_temp_trshld_high_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t stts22h_temp_trshld_high_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t stts22h_temp_trshld_low_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t stts22h_temp_trshld_low_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint8_t under_thl             : 1;
  uint8_t over_thh              : 1;
} stts22h_temp_trlhd_src_t;
int32_t stts22h_temp_trshld_src_get(const stmdev_ctx_t *ctx,
                                    stts22h_temp_trlhd_src_t *val);

/**
  *@}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /* STTS22H_REGS_H */
