#ifndef util_h
#define util_h

#define SET_BIT(REG,BIT_NUM)     REG|=(1<<(BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)     REG&=~(1<<(BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)  REG^=(1<<(BIT_NUM))
#define GET_BIT(REG,BIT_NUM)     ((REG>>(BIT_NUM))&1)
#define GET_REG (REG)            (REG)
#define SET_REG (REG)            REG=0xff
#define CLR_REG (REG)            REG=0x00
#define TOGGLE_REG (REG)         REG^=0xff
#define ASSIGN_REG (REG,VALUE)   REG=(VALUE)
#define GET_LOW_NIB (REG)       ((REG)&(0X0F))
#define SET_LOW_NIB (REG)        REG|=0X0F
#define CLR_LOW_NIB (REG)        REG)&=0XF0
#define ASSIGN_LOW_NIB (REG,VALUE)  





#endif