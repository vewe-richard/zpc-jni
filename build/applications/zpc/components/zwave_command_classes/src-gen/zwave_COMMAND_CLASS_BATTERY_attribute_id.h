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

#ifndef ZWAVE_COMMAND_CLASS_BATTERY_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_BATTERY_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_BATTERY_VERSION, ((0x80<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_BATTERY_LEVEL, ((0x80<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_REPLACE_RECHARGE, ((0x80<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_CHARGING_STATUS, ((0x80<< 8) | 0x4))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_HEALTH_MAXIMUM_CAPACITY, ((0x80<< 8) | 0x5))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_HEALTH_SCALE, ((0x80<< 8) | 0x6))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_HEALTH_PRECISION, ((0x80<< 8) | 0x7))
DEFINE_ATTRIBUTE(ATTRIBUTE_BATTERY_HEALTH_BATTERY_TEMPERATURE, ((0x80<< 8) | 0x8))


#endif  //ZWAVE_COMMAND_CLASS_BATTERY_ATTRIBUTE_ID_H

