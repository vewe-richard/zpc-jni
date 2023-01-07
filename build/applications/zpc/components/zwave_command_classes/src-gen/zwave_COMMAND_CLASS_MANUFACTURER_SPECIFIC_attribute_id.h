/******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

#ifndef ZWAVE_COMMAND_CLASS_MANUFACTURER_SPECIFIC_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_MANUFACTURER_SPECIFIC_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_MANUFACTURER_SPECIFIC_VERSION, ((0x72<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_MANUFACTURER_SPECIFIC_MANUFACTURER_ID, ((0x72<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_MANUFACTURER_SPECIFIC_PRODUCT_TYPE_ID, ((0x72<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_MANUFACTURER_SPECIFIC_PRODUCT_ID, ((0x72<< 8) | 0x4))
DEFINE_ATTRIBUTE(ATTRIBUTE_DEVICE_SPECIFIC_DEVICE_ID_TYPE, ((0x72<< 8) | 0x5))
DEFINE_ATTRIBUTE(ATTRIBUTE_DEVICE_SPECIFIC_DEVICE_ID_DATA_LENGTH_INDICATOR, ((0x72<< 8) | 0x6))
DEFINE_ATTRIBUTE(ATTRIBUTE_DEVICE_SPECIFIC_DEVICE_ID_DATA_FORMAT, ((0x72<< 8) | 0x7))
DEFINE_ATTRIBUTE(ATTRIBUTE_DEVICE_SPECIFIC_DEVICE_ID_DATA, ((0x72<< 8) | 0x8))


#endif  //ZWAVE_COMMAND_CLASS_MANUFACTURER_SPECIFIC_ATTRIBUTE_ID_H

