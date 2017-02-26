
#pragma once


namespace rtfm
{
namespace timer
{

/**
 * @brief   Convenience definition of the max SysTick duration.
 */
static const constexpr auto max_systick_duration =
  rtfm::time::system_clock::duration{SysTick_LOAD_RELOAD_Msk};

inline void pend()
{
  SCB->ICSR |= SCB_ICSR_PENDSTSET_Msk;
}

inline void initialize()
{
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk;
  SysTick->LOAD = timer::max_systick_duration.count();
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

} /* END namespace timer */
} /* END namespace rtfm */
