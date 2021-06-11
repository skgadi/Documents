#include "main_activity.h"
void MAIN_ACTIVITY::stateDispense() {
  gskRelays.on(selectedChemical);
  int timeOfDispense = timeSinceStateChange()/100;
  int remainingTime = tymEqvToCredit - timeOfDispense;
  int consumedCredit = 1+ timeOfDispense*(gskChemicals[selectedChemical].costPerLiter*(1.0/(gskChemicals[selectedChemical].timePerLiter*1.0)));
  //Serial.print("Consumed credit: ");
  //Serial.println(consumedCredit);
  int remainingCredits = gskCoins.credit - consumedCredit;
  double dispensed = timeOfDispense/(gskChemicals[selectedChemical].timePerLiter*1.0);
  if (tymOfLastDisp != timeOfDispense) {
    gskDisp.enable();
    tymOfLastDisp = timeOfDispense;
  }
  gskDisp.displayDispensing(gskChemicals[selectedChemical].costPerLiter, dispensed, remainingCredits);
  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    gskCoins.credit -= consumedCredit;
    gskRelays.stopAll();
    if (gskCoins.credit<0) {
      gskCoins.resetCredit();
      changeState(IDLE);
    }
    changeState(CREDIT);
  }
  if (remainingTime<0) {
    gskCoins.resetCredit();
    gskRelays.stopAll();
    changeState(IDLE);
  }
}
