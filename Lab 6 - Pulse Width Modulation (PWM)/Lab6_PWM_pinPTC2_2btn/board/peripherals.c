/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v15.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 15.0.1
board: FRDM-K64F
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: ef46ceb0-f7bb-436b-965a-6a3298876458
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
  - global_init: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
      - 1: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * GPIOA initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'GPIOA'
- type: 'gpio'
- mode: 'GPIO'
- custom_name_enabled: 'false'
- type_id: 'gpio_5920c5e026e8e974e6dc54fbd5e22ad7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPIOA'
- config_sets:
  - fsl_gpio:
    - enable_irq: 'true'
    - port_interrupt:
      - IRQn: 'PORTA_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'true'
      - handler_custom_name: 'SW3_GPIOA_IRQHANDLER'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void GPIOA_init(void) {
  /* Make sure, the clock gate for port A is enabled (e. g. in pin_mux.c) */
  /* Enable interrupt PORTA_IRQn request in the NVIC. */
  EnableIRQ(GPIOA_IRQN);
}

/***********************************************************************************************************************
 * GPIOC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'GPIOC'
- type: 'gpio'
- mode: 'GPIO'
- custom_name_enabled: 'false'
- type_id: 'gpio_5920c5e026e8e974e6dc54fbd5e22ad7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPIOC'
- config_sets:
  - fsl_gpio:
    - enable_irq: 'true'
    - port_interrupt:
      - IRQn: 'PORTC_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'true'
      - handler_custom_name: 'SW2_GPIOC_IRQHANDLER'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void GPIOC_init(void) {
  /* Make sure, the clock gate for port C is enabled (e. g. in pin_mux.c) */
  /* Enable interrupt PORTC_IRQn request in the NVIC. */
  EnableIRQ(GPIOC_IRQN);
}

/***********************************************************************************************************************
 * FTM0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FTM0'
- type: 'ftm'
- mode: 'EdgeAligned'
- custom_name_enabled: 'false'
- type_id: 'ftm_a206ca22312775f3c8a462078188c129'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FTM0'
- config_sets:
  - ftm_main_config:
    - ftm_config:
      - clockSource: 'kFTM_SystemClock'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - timerPrescaler: '1'
      - timerOutputFrequency: '10 kHz'
      - systemClockSource: 'BusInterfaceClock'
      - systemClockSourceFreq: 'mirrored_value'
      - faultMode: 'kFTM_Fault_Disable'
      - inputFilterPeriod: '1'
      - faultInputs:
        - 0:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 1:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 2:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 3:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
      - deadTimePrescale: 'kFTM_Deadtime_Prescale_1'
      - deadTimePeriod: '0'
      - pwmSyncMode: 'kFTM_SoftwareTrigger'
      - reloadPoints: ''
      - extTriggers: ''
      - chnlInitState: ''
      - chnlPolarity: ''
      - bdmMode: 'kFTM_BdmMode_0'
      - useGlobalTimeBase: 'false'
    - timer_interrupts: ''
    - enable_irq: 'false'
    - ftm_interrupt:
      - IRQn: 'FTM0_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'false'
  - ftm_edge_aligned_mode:
    - ftm_edge_aligned_channels_config:
      - 0:
        - channelId: ''
        - edge_aligned_mode: 'kFTM_EdgeAlignedPwm'
        - edge_aligned_pwm:
          - chnlNumber: 'kFTM_Chnl_1'
          - level: 'kFTM_HighTrue'
          - dutyValueStr: '0%'
          - enable_chan_irq: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ftm_config_t FTM0_config = {
  .prescale = kFTM_Prescale_Divide_1,
  .faultMode = kFTM_Fault_Disable,
  .faultFilterValue = 0,
  .deadTimePrescale = kFTM_Deadtime_Prescale_1,
  .deadTimeValue = 0,
  .pwmSyncMode = kFTM_SoftwareTrigger,
  .reloadPoints = 0,
  .extTriggers = 0,
  .chnlInitState = 0,
  .chnlPolarity = 0,
  .bdmMode = kFTM_BdmMode_0,
  .useGlobalTimeBase = false
};

const ftm_chnl_pwm_config_param_t FTM0_pwmSignalParams[] = { 
  {
    .chnlNumber = kFTM_Chnl_1,
    .level = kFTM_HighTrue,
    .dutyValue = 0,
  }
};

static void FTM0_init(void) {
  FTM_Init(FTM0_PERIPHERAL, &FTM0_config);
  FTM_SetTimerPeriod(FTM0_PERIPHERAL, FTM0_TIMER_MODULO_VALUE);
  FTM_SetupPwmMode(FTM0_PERIPHERAL, FTM0_pwmSignalParams, sizeof(FTM0_pwmSignalParams) / sizeof(ftm_chnl_pwm_config_param_t), kFTM_EdgeAlignedPwm);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  GPIOA_init();
  GPIOC_init();
  FTM0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
