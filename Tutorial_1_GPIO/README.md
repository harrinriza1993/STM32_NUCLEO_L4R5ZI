# General purpose input output
### Output
#### Step 1 : Configure the clock

- Enable the peripheral clock for GPIOX Port (where x is A or B or C etc). The peripheral clock for GPIOX (AHB2) can be found in the following figure.

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
RCC_AHB2ENR = RCC_AHB2ENR | (1 << 0);
```

#### Step 2 : Configure pin as output  


- `GPIOx_MODER` is used to configure the pin as output and we have to write `01` as shown in the following figure.
![](images/GPIOx_MODER.png)
- The register adress offsets and reset values are in the following table

- Find the address of the GPIOx regiser [GPIOx_BASE + GPIOx_OFFSET] where x = A, B ..... I
- For examble if the pin is PA0 then

```sh
#define  GPIOA_BASE_ADDRESS//  0x48000000
#define GPIOx_MODER_OFFSET// 0x00
#define GPIOA_MODER (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
```



- The bit is set
- From the below digram it is known that output mode is set according to the pin number of the pin which we use as output. 
- Example if PA0 is set as output pin, then 0th bit (0 + 0) and 1st bit(0 + 0 + 1) should be set as output mode.


```sh
 GPIOA_MODER = GPIOA_MODER | (1 << (pin_number + pin_number));
 GPIOA_MODER = GPIOA_MODER &  ~(1 << (pin_number + pin_number + 1)); 
```

#### Step 3 : Set / clear the pin
- To set / clear the pin GPIOX_BSRR register is used. The register adress offsets and reset values are in the following table
- 
- Find the address of the GPIOx_BSRR regiser [GPIOx_BASE_ADDRESS + GPIO_BSRR_OFFSET] where x = A, B ..... I
- For examble if the pin is PA0 then
```sh
#define  GPIOA_BASE_ADDRESS//  0x48000000
#define GPIO_BSRR_OFFSET// 0x18
#define GPIOA_BSRR (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
```
![](images/RCCRegisterMap.png)

-  Example,To set the bit PA0  then 0th bit of the register (GPIOx_BSRR) should be set to 1.
-  To clear the bit, the 0th bit of the register (GPIOx_BSRR) should be set to 0 and 23rd (0 + 16 th bit) bit should be set to 1

![](images/GPIOx_BSRR.png)

  ```sh
 GPIOA_BSRR = GPIOA_BSRR | (1 << pin_number);// To set the pin
 GPIOA_BSRR = GPIOA_BSRR & ~(1 << pin_number);// To clear the pin
 GPIOA_BSRR = GPIOA_BSRR | (1 << (pin_number + 16));
```

