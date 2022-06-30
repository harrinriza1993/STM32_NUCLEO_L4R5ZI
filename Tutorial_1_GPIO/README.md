# General purpose input output
### Output
#### Step 1 : Configure the clock

- Enable the peripheral clock for GPIOX Port (where x is A or B or C etc). The peripheral clock for GPIOX (AHB2) can be found in the following figure.

![](images/PeripheralClock.png)

- Find the address of the `RCC_AHB2ENR` register [RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET] (0x40021000 + 0x4C)

```sh
#define RCC_BASE_ADDRESS 0x40021000 // Look at the RCC regiser map
#define RCC_AHB2ENR_OFFSET 0x4C
#define RCC_AHB1ENR (*((volatile uint32_t*) (RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET)))
```
![](images/RCCRegisterMap.png)

![](images/RCCAHb2ENr.png)

- Example, If we set `PA0` as output pin then 0th bit of the register (RCC_AHB2ENR) should be set to `1`.
```sh
RCC_AHB2ENR = RCC_AHB2ENR | (1 << 0);
```

#### Step 2 : Configure pin as output  


- `GPIOx_MODER` is used to configure the pin as output and we have to write `01` to the specific bit as shown in the following figure.

![](images/GPIOx_MODER.png)

- Find the address of the GPIOx regiser [GPIOx_BASE + GPIOx_MODE_OFFSET] where x = A, B ..... I
- Example, if we configure `PA0` as output. we have to find the base address of `GPIOA` (ref: GPIO register map) + offset of the mode register (`0x00`)

```sh
#define  GPIOA_BASE_ADDRESS  0x48000000
#define GPIOx_MODER_OFFSET 0x00
#define GPIOA_MODER (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
```

- Set `01` in `GPIOA_MODER` (`MODE[1:0]` ) register.


```sh
 GPIOA_MODER = GPIOA_MODER | (1 << 0);  
 GPIOA_MODER = GPIOA_MODER &  ~(1 << 1);   
```

#### Step 3 : Set the pin
- To set the pin GPIOX_BSRR register is used.
- Find the address of the GPIOx_BSRR regiser [GPIOx_BASE_ADDRESS + GPIO_BSRR_OFFSET] where x = A, B ..... I

```sh
#define  GPIOA_BASE_ADDRESS  0x48000000
#define GPIO_BSRR_OFFSET 0x18
#define GPIOA_BSRR (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
```

-  Example,To set PA0, 0th bit of the register (GPIOx_BSRR) should be set to 1.


![](images/GPIOx_BSRR.png)

  ```sh
 GPIOA_BSRR = 1;
```

#### Step 4 : Clear the pin
- To clear the pin GPIOX_BRR register is used.
- Find the address of the GPIOx_BRR regiser [GPIOx_BASE_ADDRESS + GPIO_BSRR_OFFSET] where x = A, B ..... I

```sh
#define  GPIOA_BASE_ADDRESS  0x48000000
#define GPIO_BRR_OFFSET 0x28
#define GPIOA_BRR (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIO_BRR_OFFSET)))
```

-  Example,To set PA0, 0th bit of the register (GPIOx_BRR) should be set to 1.


![](images/BRR_Register.png)

  ```sh
 GPIOA_B2RR = 1;
```
