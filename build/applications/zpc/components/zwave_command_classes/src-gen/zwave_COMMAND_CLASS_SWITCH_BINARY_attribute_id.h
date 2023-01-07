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

#ifndef ZWAVE_COMMAND_CLASS_SWITCH_BINARY_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_SWITCH_BINARY_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_SWITCH_BINARY_VERSION, ((0x25<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_SWITCH_BINARY_CURRENT_VALUE, ((0x25<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_SWITCH_BINARY_TARGET_VALUE, ((0x25<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_SWITCH_BINARY_DURATION, ((0x25<< 8) | 0x4))


#endif  //ZWAVE_COMMAND_CLASS_SWITCH_BINARY_ATTRIBUTE_ID_H

