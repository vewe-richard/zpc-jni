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

#ifndef ZWAVE_COMMAND_CLASS_ZWAVEPLUS_INFO_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_ZWAVEPLUS_INFO_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_ZWAVEPLUS_INFO_VERSION, ((0x5E<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_ZWAVEPLUS_INFO_Z_WAVE_VERSION, ((0x5E<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_ZWAVEPLUS_INFO_ROLE_TYPE, ((0x5E<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_ZWAVEPLUS_INFO_NODE_TYPE, ((0x5E<< 8) | 0x4))
DEFINE_ATTRIBUTE(ATTRIBUTE_ZWAVEPLUS_INFO_INSTALLER_ICON_TYPE, ((0x5E<< 8) | 0x5))
DEFINE_ATTRIBUTE(ATTRIBUTE_ZWAVEPLUS_INFO_USER_ICON_TYPE, ((0x5E<< 8) | 0x6))


#endif  //ZWAVE_COMMAND_CLASS_ZWAVEPLUS_INFO_ATTRIBUTE_ID_H

