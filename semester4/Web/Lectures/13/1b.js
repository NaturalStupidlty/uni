function cost(hryvni, kopiyky) {
  let totalCost = hryvni * 100 + kopiyky;

  let hryvnaAmount = Math.floor(totalCost / 100);
  let kopiykaAmount = totalCost % 100;
  
  let hryvnaString = hryvnaAmount === 1 ? "гривня" : "гривні";
  let kopiykaString = kopiykaAmount === 1 ? "копійка" : "копійки";
  if (hryvnaAmount % 10 == 0) {
      hryvnaString = "гривень";
  }
    if (kopiykaAmount % 10 == 0) {
      kopiykaString = "копійок";
  }
  
  let output = `Вартість замовлення: ${hryvnaAmount} ${hryvnaString} ${kopiykaAmount} ${kopiykaString}`;
  console.log(output);
}
cost(2, 75);
cost(0, 1);
cost(25, 3);
cost(20, 102);