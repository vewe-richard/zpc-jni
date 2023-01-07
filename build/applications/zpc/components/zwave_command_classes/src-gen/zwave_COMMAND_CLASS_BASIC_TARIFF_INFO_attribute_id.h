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

#ifndef ZWAVE_COMMAND_CLASS_BASIC_TARIFF_INFO_ATTRIBUTE_ID_H
#define ZWAVE_COMMAND_CLASS_BASIC_TARIFF_INFO_ATTRIBUTE_ID_H


DEFINE_ATTRIBUTE(ATTRIBUTE_COMMAND_CLASS_BASIC_TARIFF_INFO_VERSION, ((0x36<< 8) | 1))
DEFINE_ATTRIBUTE(ATTRIBUTE_BASIC_TARIFF_INFO_TOTAL_NO_IMPORT_RATES, ((0x36<< 8) | 0x2))
DEFINE_ATTRIBUTE(ATTRIBUTE_BASIC_TARIFF_INFO_E_CURRENT_RATE_IN_USE, ((0x36<< 8) | 0x3))
DEFINE_ATTRIBUTE(ATTRIBUTE_BASIC_TARIFF_INFO_E_RATE_CONSUMPTION_REGISTER, ((0x36<< 8) | 0x4))
DEFINE_ATTRIBUTE(ATTRIBUTE_BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_HOURS, ((0x36<< 8) | 0x5))
DEFINE_ATTRIBUTE(ATTRIBUTE_BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_MINUTES, ((0x36<< 8) | 0x6))
DEFINE_ATTRIBUTE(ATTRIBUTE_BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_SECONDS, ((0x36<< 8) | 0x7))


#endif  //ZWAVE_COMMAND_CLASS_BASIC_TARIFF_INFO_ATTRIBUTE_ID_H

