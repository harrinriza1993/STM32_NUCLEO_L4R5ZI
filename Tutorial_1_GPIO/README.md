# General purpose input output
### Output
#### Step 1 : Configure the clock

- Enable the peripheral clock for GPIOX Port (where x is A or B or C etc). The peripheral clock for GPIOX (AHB2) can be found in the following figure.
- 
![](images/PeripheralClock.png)

- Find the address of the RCC_AHB2ENR register [RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET] (0x40021000 + 0x4C)

```sh
#define RCC_BASE_ADDRESS 0x40021000 // Look at the RCC regiser map
#define RCC_AHB2ENR_OFFSET 0x4C
#define RCC_AHB1ENR (*((volatile uint32_t*) (RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET)))
```
![](images/RCCRegisterMap.png)

![](images/RCCAHb2ENr.png)

- Example, If we set PA0 as output pin then 0th bit of the register (RCC_AHB2ENR) should be set to 1.
```sh
RCC_AHB1ENR = RCC_AHB1ENR | (1 << 0);
```

#### Step 2 : Configure pin as output
![](images/GPIOx_MODER.png)
    To confiure the pin as output pin  GPIOx_MODER register is used. Set the bit(make the bit to 1) which is double the number of pin number and clear the bit(make the bit to 0) which is  the next number to the double the number of pin number. For examble if we take a pin PA5 as output pin then double the number of 5 is 10 and the next number is 11. In the diagram it is clerly mentioned if we have to configure the pin to output we have to make 11th bit  to 0 and 10th bit to 1. The address of the register is found according to the port used in the pin. Base address of GPIO changes according to the port used in pin , offset address is same. If it is A port then add GPIOA base address + GPIOx offset address( 0x48000000 + 0x00). 
#### Step 3 : Set / clear the pin
![](images/GPIOx_BSRR.png)
   To Set the pin,  that means to make led on  set the bit in GPIOx_BSRR register. Depending on the pin number the bit is made  on.For example if we take pin PB7, then 7th bit in the register should be 1.
   If we need to make led off, make the corresponding bit with the pin number to 0 and set the bit (pin number + 16 th bit) to 1. For example to make PB7 to off set the 7th bit to 0 and 23rd(7 + 16) bit to 1. The address of register is found by adding GPIO Base address and GPIO BSRR offset address. Base address changes but offset remains same for all port. If it is port c then add GPIOC base address and GPIO BSRR offset address( 0x48000800 + 0x18).
   




