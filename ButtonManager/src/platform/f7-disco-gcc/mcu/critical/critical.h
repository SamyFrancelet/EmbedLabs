#ifndef CRITICAL_H
#define CRITICAL_H

extern volatile int bInISR;     ///< Defined in critical.cpp

int inISR();                    ///< Returns 1 if in an interrupt service routine (ISR), 0 otherwise.
void enterCritical();           ///< Disables all interrupts.
void exitCritical();            ///< Enables all interrupts.

#endif /* CRITICAL_H */
