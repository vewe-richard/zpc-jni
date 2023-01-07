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

#ifndef ZWAVE_COMMAND_CLASS_DOOR_LOCK_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_DOOR_LOCK_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_DOOR_LOCK_VERSION, ((0x62<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_CONFIGURATION_OPERATION_TYPE, ((0x62<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_CONFIGURATION_INSIDE_DOOR_HANDLES_STATE, ((0x62<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_CONFIGURATION_OUTSIDE_DOOR_HANDLES_STATE, ((0x62<< 8) | 0x4))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_CONFIGURATION_LOCK_TIMEOUT_MINUTES, ((0x62<< 8) | 0x5))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_CONFIGURATION_LOCK_TIMEOUT_SECONDS, ((0x62<< 8) | 0x6))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_OPERATION_DOOR_LOCK_MODE, ((0x62<< 8) | 0x7))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_OPERATION_INSIDE_DOOR_HANDLES_MODE, ((0x62<< 8) | 0x8))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_OPERATION_OUTSIDE_DOOR_HANDLES_MODE, ((0x62<< 8) | 0x9))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_OPERATION_DOOR_CONDITION, ((0x62<< 8) | 0xa))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_OPERATION_LOCK_TIMEOUT_MINUTES, ((0x62<< 8) | 0xb))
DEFINE_ATTRIBUTE(ATTRIBUTE_DOOR_LOCK_OPERATION_LOCK_TIMEOUT_SECONDS, ((0x62<< 8) | 0xc))


#endif  //ZWAVE_COMMAND_CLASS_DOOR_LOCK_ATTRIBUTE_ID_H

