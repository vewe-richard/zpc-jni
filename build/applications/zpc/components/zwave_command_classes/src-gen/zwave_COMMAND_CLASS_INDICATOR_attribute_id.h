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

#ifndef ZWAVE_COMMAND_CLASS_INDICATOR_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_INDICATOR_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_INDICATOR_VERSION, ((0x87<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_INDICATOR_INDICATOR_VALUE, ((0x87<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_INDICATOR_INDICATOR_ID, ((0x87<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_INDICATOR_PROPERTY_ID, ((0x87<< 8) | 0x4))
DEFINE_ATTRIBUTE(ATTRIBUTE_INDICATOR_SUPPORTED_PROPERTY_SUPPORTED_BIT_MASK, ((0x87<< 8) | 0x5))


#endif  //ZWAVE_COMMAND_CLASS_INDICATOR_ATTRIBUTE_ID_H

