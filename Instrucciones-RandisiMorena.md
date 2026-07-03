Instrucciones

**Caso \#1:**

Descripción:  
Cargar valores específicos en los registros t3(R\[11\])yt3(R\[11\])yt4 (R\[12\]) usando la combinación LUI \+ ORI para poder probar las instrucciones aritméticas y lógicas.

Valores a cargar:  
**$t3 (R\[11\])** \= 0x0000000C (12 decimal)  
**$t4 (R\[12\])** \= 0x00000003 (3 decimal)

Instrucciones utilizadas:

1. LUI $t3, 0

   Formato L: opcode | rs | rt | h | imm

   

   Instrucción completa: 00111 00000 01011 0 0000000000000000

   Hexadecimal: 0x38160000

   

2. ORI t3, t3, 12  
   Formato L: opcode | rs | rt | h | imm  
   Instrucción completa: 00101 01011 01011 0 0000000000001100  
   Hexadecimal: 0x2AD6000C  
     
3. LUI $t4, 0  
   Formato: opcode | rs | rt | h | imm  
   Instrucción completa: 00111 00000 01100 0 0000000000000000  
   Hexadecimal: 0x38180000  
     
4. ORI t4,t4, 3  
   **Formato L:** opcode | rs | rt | h | imm  
   Instrucción completa: 00101 01100 01100 0 0000000000000011  
   Hexadecimal: 0x2B180003  
   

Precondiciones: Ninguna (restet inicial)

RTM32\> reset  
System reset sequence complete. Target PC: 0xF0000000 (Mode: KERNEL)  
RTM32\> s PC 0x00  
Program Counter (PC) set to 0x00000000  
RTM32\> s \[0x00\] 0x38160000  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000004  
RTM32\> s \[0x04\] 0x2AD6000C  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000008  
RTM32\> s \[0x08\] 0x38180000  
RTM32\> n 1  
Stepped instructions. Target PC: 0x0000000C  
RTM32\> s \[0x0C\] 0x2B180003  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000010  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000000   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000010  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x0000000C | Size: 0x00000004 | Type: FETCH

* **R\[11\] \= 0x0000000C** (12 en decimal)  
* **R\[12\] \= 0x00000003** (3 en decimal)  
* **PC \= 0x00000010** (avanzó 4 instrucciones × 4 bytes \= 16 bytes \= 0x10)  
* Registros no utilizados permanecen en 0

Conclusiones

**Funciona** \- La combinación LUI \+ ORI carga correctamente los valores en los registros. LUI coloca el valor inmediato en los 16 bits superiores del registro (en este caso 0), y ORI combina el valor inmediato en los 16 bits inferiores mediante una operación OR.

**Caso \#2:**  
Descripción: Probar la instrucción ADD sumando los valores previamente cargados en los registros t3(R\[11\]=12)yt3(R\[11\]=12)yt4 (R\[12\] \= 3), almacenando el resultado en $t0 (R\[8\]).

Instrucciones utilizadas: ADD t0,t3 $t4

Formato R: opcode | rs | rt | rd | aux | X | func

Instrucción completa: 0000 0010 1101 1000 1000 0000 0001 1100  
Hexadecimal: 0x02D8801C

**Precondiciones:**

* **R\[11\] \= 0x0000000C (12)**  
* **R\[12\] \= 0x00000003 (3)**  
* **PC \= 0x00000010**

**RTM32\> s PC 0x10**  
**Program Counter (PC) set to 0x00000010**  
**RTM32\> s \[0x10\] 0x02D8801C**  
**RTM32\> n 1**  
**Stepped instructions. Target PC: 0x00000014**  
**RTM32\> r**  
**\=== General Purpose Registers \===**  
**R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000**  
**R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000**  
**R\[ 8\]: 0x0000000F   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C**  
**R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000**  
**R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000**  
**R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000**  
**R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000**  
**R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000**

**\=== Control & Special Registers \===**  
**PC      : 0x00000014  CAUSE   : 0x00000000  EPC     : 0x00000000**  
**BADVADR : 0x00000000  VBR     : 0xF0000000**

**Execution State:**  
**Mode: KERNEL | Flags: \[-----\]**

**Last Memory Operation:**  
**Address: 0x00000010 | Size: 0x00000004 | Type: FETCH**

* **R\[8\] \= 0x0000000F (12 \+ 3 \= 15 en decimal)**  
* **R\[11\] \= 0x0000000C (no modificado)**  
* **R\[12\] \= 0x00000003 (no modificado)**  
* **PC \= 0x00000014 (avanzó 4 bytes)**

**![][image1]**  
**Conclusiones:** **Funciona** \- La instrucción ADD suma correctamente los valores de los registros fuente (t3yt3yt4) y almacena el resultado en el registro destino ($t0). Los registros fuente no se modifican y el PC avanza correctamente.

**Caso \#3:**  
**Descripción:** Probar la instrucción SUB restando los valores previamente cargados en los registros t3(R\[11\]=12)yt3(R\[11\]=12)yt4 (R\[12\] \= 3), almacenando el resultado en $t0 (R\[8\]).

**Instrucciones utilizadas:** SUB t0,t3, $t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 011101  
**Hexadecimal:**0x02D8801D

**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000014

RTM32\> s PC 0x14  
Program Counter (PC) set to 0x00000014  
RTM32\> s \[0x14\] 0x02D8801D  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000018  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000009   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000018  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000014 | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x00000009 (12 \- 3 \= 9 en decimal)**  
* **R\[11\] \= 0x0000000C (no modificado)**  
* **R\[12\] \= 0x00000003 (no modificado)**  
* **PC \= 0x00000018 (avanzó 4 bytes)**

![][image2]

**Conclusiones: Funciona \-** La instrucción SUB resta correctamente el valor de t4 al valor de valor t3 y almacena el resultado en $t0. Los registros fuente no se modifican.

**Caso \#4:**

**Descripción:** Probar la instrucción MUL multiplicando los valores previamente cargados en los registros t3 (R\[11\]=12) y t4 (R\[12\] \= 3), almacenando el resultado en $t0 (R\[8\]).

**Instrucciones utilizadas:** MUL t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 010101  
**Hexadecimal:** 0x02D88015

**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000018

RTM32\> s \[0x18\] 0x02D88015  
RTM32\> n 1  
Stepped instructions. Target PC: 0x0000001C  
RTM32\>   
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000024   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x0000001C  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000018 | Size: 0x00000004 | Type: FETCH

20:29:21 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000018  
20:29:21 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000018  
20:29:21 TRACE \[src/cpu.c:466\]: Instruction: 0x02D88015  
20:29:21 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
20:29:21 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
20:29:21 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
20:29:21 TRACE \[src/debug/debug.c:329\]: Read returned n \= 2, errno \= 0 (Success)  
20:29:21 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 0D 0A   
20:29:21 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
20:29:28 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
20:29:28 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
20:29:28 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
20:29:28 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
20:29:28 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
20:29:28 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
20:29:28 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
20:29:28 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

* **R\[8\] \= 0x00000024** (12 × 3 \= 36 en decimal \= 0x24)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x0000001C** (avanzó 4 bytes)

**Conclusiones:** Funciona \- La instrucción MUL multiplica correctamente los valores de los registros fuente y almacena el resultado en el registro destino. El resultado 0x24 (36 decimal) es correcto para 12 × 3\.

**Caso \#5:**

**Descripción:** Probar la instrucción AND realizando una operación lógica AND bit a bit entre los valores en t3 (R\[11\]=12=0x0C) y t4 (R\[12\] \= 3 \= 0x03), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:**   
12 \= 0x0C \= 0000 1100  
 3 \= 0x03 \= 0000 0011  
AND      \= 0000 0000 \= 0x00 \= 0  
**Instrucciones utilizadas:** AND t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 001000  
**Hexadecimal:** 0x02D88008

**Precondiciones:** 

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x0000001C

RTM32\> s PC 0x1C  
Program Counter (PC) set to 0x0000001C  
RTM32\> s \[0x1C\] 0x02D88008  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000020  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000000   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000020  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x0000001C | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x00000000** (12 AND 3 \= 0\)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x00000020**

20:46:34 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x0000001C  
20:46:34 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x0000001C  
20:46:34 TRACE \[src/cpu.c:466\]: Instruction: 0x02D88008  
20:46:34 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
20:46:34 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
20:46:34 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
20:46:37 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
20:46:37 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
20:46:37 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
20:46:37 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
20:46:37 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
20:46:37 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
20:46:37 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
20:46:37 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
20:46:37 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6

**Conclusiones: Funciona** \- La instrucción AND realiza correctamente la operación lógica AND bit a bit. Como 12 (1100) y 3 (0011) no tienen bits en común, el resultado es 0\.

**Caso \#6:**

**Descripción:** Probar la instrucción OR realizando una operación lógica OR bit a bit entre los valores en t3 (R\[11\]=12=0x0C) y t4 (R\[12\] \= 3 \= 0x03), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:**  
12 \= 0x0C \= 0000 1100  
 3 \= 0x03 \= 0000 0011  
OR       \= 0000 1111 \= 0x0F \= 15

**Instrucciones utilizadas:** OR t0, t3, $t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 001001  
**Hexadecimal:** 0x02D88009

**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000020

RTM32\> s PC 0x20  
Program Counter (PC) set to 0x00000020  
RTM32\> s \[0x20\] 0x02D88009  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000024  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x0000000F   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000024  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000020 | Size: 0x00000004 | Type: FETCH

* R\[8\] \= 0x0000000F (12 OR 3 \= 15\)  
* R\[11\] \= 0x0000000C (no modificado)  
* R\[12\] \= 0x00000003 (no modificado)  
* PC \= 0x00000024

20:52:30 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000020  
20:52:30 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000020  
20:52:30 TRACE \[src/cpu.c:466\]: Instruction: 0x02D88009  
20:52:30 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
20:52:30 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
20:52:30 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
20:52:32 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
20:52:32 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
20:52:32 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
20:52:32 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
20:52:32 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
20:52:32 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
20:52:32 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
20:52:32 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones:** Funciona \- La instrucción OR realiza correctamente la operación lógica OR bit a bit. El resultado 0x0F (15) es correcto.

**Caso \#7:**   
**Descripción:** Probar la instrucción XOR realizando una operación lógica XOR (OR exclusivo) bit a bit entre los valores en t3 (R\[11\]=12=0x0C) y t4 (R\[12\] \= 3 \= 0x03), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:**   
12 \= 0x0C \= 0000 1100  
 3 \= 0x03 \= 0000 0011  
XOR      \= 0000 1111 \= 0x0F \= 15  
**Instrucciones utilizadas:** XOR t0,t3, $t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 001010  
**Hexadecimal:** 0x02D8800A  
**Precondiciones:** 

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000024

RTM32\> s PC 0x24  
Program Counter (PC) set to 0x00000024  
RTM32\> s \[0x24\] 0x02D8800A  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000028  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x0000000F   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000028  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000024 | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x0000000F** (12 XOR 3 \= 15\)  
* ✅ **R\[11\] \= 0x0000000C** (no modificado)  
* ✅ **R\[12\] \= 0x00000003** (no modificado)  
* ✅ **PC \= 0x00000028**

21:04:45 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000024  
21:04:45 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000024  
21:04:45 TRACE \[src/cpu.c:466\]: Instruction: 0x02D8800A  
21:04:45 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
21:04:45 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
21:04:45 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
21:04:47 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
21:04:47 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
21:04:47 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
21:04:47 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
21:04:47 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
21:04:47 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
21:04:47 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
21:04:47 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción XOR realiza correctamente la operación lógica XOR bit a bit. El resultado 0x0F (15) es correcto.

**Caso \#8:**

**Descripción:** Probar la instrucción NOR realizando una operación lógica NOR (OR negado) bit a bit entre los valores en t3 (R\[11\]=12=0x0C) y t4 (R\[12\] \= 3 \= 0x03), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:**  
12 \= 0x0C \= 0000 1100  
 3 \= 0x03 \= 0000 0011  
OR       \= 0000 1111 \= 0x0F  
NOR      \= NOT(OR) \= 1111 0000 \= 0xF0 \= 240

**Instrucción completa:** 00000 01011 01100 01000 00000 0 001011  
**Hexadecimal:** 0x02D8800B  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000028

RTM32\> s PC 0x28  
Program Counter (PC) set to 0x00000028  
RTM32\> s \[0x28\] 0x02D8800B  
RTM32\> n 1  
Stepped instructions. Target PC: 0x0000002C  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0xFFFFFFF0   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x0000002C  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000028 | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0xFFFFFFF0** (12 NOR 3 \= 0xFFFFFFF0)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x0000002C**

21:10:56 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000028  
21:10:56 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000028  
21:10:56 TRACE \[src/cpu.c:466\]: Instruction: 0x02D8800B  
21:10:56 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
21:10:56 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
21:10:56 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
21:10:57 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
21:10:57 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
21:10:57 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
21:10:57 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
21:10:57 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
21:10:57 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
21:10:57 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
21:10:57 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones:** **Funciona** \- La instrucción NOR realiza correctamente la operación lógica NOR bit a bit. Como OR de 12 y 3 da 0x0F, su negación es 0xFFFFFFF0.

**Caso \#9:**  
**Descripción:** Probar la instrucción DIV realizando una división con signo entre los valores en t3(R\[11\]=12) y t4 (R\[12\] \= 3), almacenando el cociente en $t0 (R\[8\]).

**Cálculo esperado:** 12 ÷ 3 \= 4 (cociente)  
**Instrucciones utilizadas:** DIV t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 011000  
**Hexadecimal:** 0x02D88018  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x0000002C

RTM32\> s PC 0x2C  
Program Counter (PC) set to 0x0000002C  
RTM32\> s \[0x2C\] 0x02D88018  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000030  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000004   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000030  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x0000002C | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x00000004** (12 ÷ 3 \= 4\)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x00000030**

21:16:31 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x0000002C  
21:16:31 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x0000002C  
21:16:31 TRACE \[src/cpu.c:466\]: Instruction: 0x02D88018  
21:16:31 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
21:16:31 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
21:16:31 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
21:16:34 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
21:16:34 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
21:16:34 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
21:16:34 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
21:16:34 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
21:16:34 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
21:16:34 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
21:16:34 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción DIV realiza correctamente la división con signo. El cociente 4 es correcto para 12 ÷ 3\.

**Caso \#10:**  
**Descripción:** Probar la instrucción DIVU realizando una división sin signo entre los valores en t3(R\[11\]=12) y t4 (R\[12\] \= 3), almacenando el cociente en $t0 (R\[8\]).

**Cálculo esperado:** 12 ÷ 3 \= 4 (cociente)  
**Instrucciones utilizadas:** DIVU t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 011001  
**Hexadecimal:** 0x02D88019  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000030

RTM32\> s PC 0x30  
Program Counter (PC) set to 0x00000030  
RTM32\> s \[0x30\] 0x02D88019  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000034  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000004   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000034  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000030 | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x00000004** (12 ÷ 3 \= 4\)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x00000034**

23:07:31 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000030  
23:07:31 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000030  
23:07:31 TRACE \[src/cpu.c:466\]: Instruction: 0x02D88019  
23:07:31 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
23:07:31 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:07:31 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:07:33 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:07:33 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:07:33 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:07:33 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:07:33 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:07:33 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:07:33 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:07:33 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción DIVU realiza correctamente la división sin signo. Como ambos valores son positivos, el resultado es idéntico a DIV.

**Caso \#11:**  
**Descripción:** Probar la instrucción REST (resto) calculando el residuo de la división con signo entre los valores en 3 (R\[11\]=12) y t4 (R\[12\] \= 3), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:** 12 % 3 \= 0 (resto)  
**Instrucciones utilizadas:** REST t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 000000 01011 01100 01000 00000 0 011010  
**Hexadecimal:** 0x02D8801A  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000034

RTM32\> s PC 0x34  
Program Counter (PC) set to 0x00000034  
RTM32\> s \[0x34\] 0x02D8801A  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000038  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000000   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000038  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000034 | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x00000000 (12 % 3 \= 0\)**  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x00000038**

23:13:33 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000034  
23:13:33 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000034  
23:13:33 TRACE \[src/cpu.c:466\]: Instruction: 0x02D8801A  
23:13:33 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
23:13:33 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:13:33 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:13:37 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:13:37 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:13:37 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:13:37 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:13:37 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:13:37 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:13:37 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:13:37 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción REST calcula correctamente el resto de la división con signo. Como 12 ÷ 3 es exacta, el resto es 0\.

**Caso \#12:**  
**Descripción:** Probar la instrucción RESTU (resto sin signo) calculando el residuo de la división sin signo entre los valores en 3 (R\[11\]=12) y t4 (R\[12\] \= 3), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:** 12 % 3 \= 0 (resto)  
**Instrucciones utilizadas:** RESTU t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01011 01100 01000 00000 0 011011  
**Hexadecimal:** 0x02D8801B  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000038

RTM32\> s PC 0x38  
Program Counter (PC) set to 0x00000038  
RTM32\> s \[0x38\] 0x02D8801B  
RTM32\> n 1  
Stepped instructions. Target PC: 0x0000003C  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000000   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x0000003C  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

Execution State:  
Mode: KERNEL | Flags: \[-----\]

Last Memory Operation:  
Address: 0x00000038 | Size: 0x00000004 | Type: FETCH

* **R\[8\] \= 0x00000000** (12 % 3 \= 0\)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x0000003C**

23:18:15 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000038  
23:18:15 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000038  
23:18:15 TRACE \[src/cpu.c:466\]: Instruction: 0x02D8801B  
23:18:15 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
23:18:15 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:18:15 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:18:18 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:18:18 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:18:18 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:18:18 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:18:18 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:18:18 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:18:18 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:18:18 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción RESTU calcula correctamente el resto de la división sin signo. Como ambos valores son positivos, el resultado es idéntico a REST.

**Caso \#13:**  
**Descripción:** Probar la instrucción SLL (Shift Left Logical) desplazando el valor en t3 (R\[11\] \= 12 \= 0x0C) 2 posiciones a la izquierda , almacenando resultado t3 (R\[11\] \= 12 \= 0x0C) 2 posiciones a la izquierda, almacenando resultado t0 (R\[8\]).

**Cálculo esperado:**   
12 \= 0x0C \= 0000 1100  
12 \<\< 2 \= 0011 0000 \= 0x30 \= 48  
**Instrucciones utilizadas:** SLL t0,t3,2  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 00000 01011 01000 00010 0 000000  
**Hexadecimal:** 0x002D0200  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* PC \= 0x0000003C

RTM32\> s PC 0x3C  
Program Counter (PC) set to 0x0000003C  
RTM32\> s \[0x3C\] 0x002D0200  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000040  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000030   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000040  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

* **R\[8\] \= 0x00000030** (12 \<\< 2 \= 48 \= 0x30)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **PC \= 0x00000040**

23:23:58 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x0000003C  
23:23:58 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x0000003C  
23:23:58 TRACE \[src/cpu.c:466\]: Instruction: 0x002D0200  
23:23:58 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
23:23:58 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:23:58 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:23:59 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:23:59 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:23:59 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:23:59 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:23:59 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:23:59 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:23:59 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:23:59 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción SLL desplaza correctamente los bits hacia la izquierda, insertando ceros por la derecha. El resultado 0x30 (48) es correcto para 12 \<\< 2\.

**Caso \#14:**  
**Descripción:** Probar la instrucción SRL (Shift Right Logical) desplazando el valor en t3 (R\[11\] \= 12 \= 0x0C) 2 posiciones a la derecha, almacenando resultado t3 (R\[11\] \= 12 \= 0x0C) 2 posiciones aladerecha, almacenando resultado t0 (R\[8\]).

**Cálculo esperado:**   
12 \= 0x0C \= 0000 1100  
12 \>\> 2 \= 0000 0011 \= 0x03 \= 3  
**Instrucciones utilizadas:** SRL t0,t0,t3, 2  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 00000 01011 01000 00010 0 000001  
**Hexadecimal:** 0x002D0201  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* PC \= 0x00000040

RTM32\> s PC 0x40  
Program Counter (PC) set to 0x00000040  
RTM32\> s \[0x40\] 0x002D0201  
RTM32\> n 1  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000003   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000044  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

* **R\[8\] \= 0x00000003** (12 \>\> 2 \= 3\)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **PC \= 0x00000044**

23:30:48 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000040  
23:30:48 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000040  
23:30:48 TRACE \[src/cpu.c:466\]: Instruction: 0x002D0201  
23:30:48 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
23:30:48 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:30:48 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:30:50 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:30:50 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:30:50 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:30:50 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:30:50 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:30:50 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:30:50 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:30:50 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción SRL desplaza correctamente los bits hacia la derecha, insertando ceros por la izquierda. El resultado 0x03 (3) es correcto para 12 \>\> 2\.

**Caso \#15:**  
**Descripción:** Probar la instrucción SRA (Shift Right Arithmetic) desplazando un valor negativo 2 posiciones a la derecha, preservando el bit de signo. Para este caso, vamos a usar un valor negativo: \-8 \= 0xFFFFFFF8

**Precondiciones adicionales:** cargamos \-8 en $t3  
RTM32\> s PC 0x44  
Program Counter (PC) set to 0x00000044  
RTM32\> s \[0x44\] 0x3816FFFF  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000048  
RTM32\> s \[0x48\] 0x2AD6FFF8  
RTM32\> n 1  
Stepped instructions. Target PC: 0x0000004C

**Cálculo esperado:**  
\-8 \= 0xFFFFFFF8 \= 1111 1111 1111 1111 1111 1111 1111 1000  
\-8 \>\> 2 \= 1111 1111 1111 1111 1111 1111 1111 1110 \= 0xFFFFFFFE \= \-2  
**Instrucciones utilizadas:** SRA t0,t3,2  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 00000 01011 01000 00010 0 000010  
**Hexadecimal:** 0x002D0202

RTM32\> s PC 0x4C  
Program Counter (PC) set to 0x0000004C  
RTM32\> s \[0x4C\] 0x002D0202  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000050  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0xFFFFFFFE   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0xFFFFFFF8  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000050  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

* **R\[8\] \= 0xFFFFFFFE** (-8 \>\> 2 \= \-2)  
* **R\[11\] \= 0xFFFFFFF8** (no modificado)  
* **PC \= 0x00000050**

23:38:20 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x0000004C  
23:38:20 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x0000004C  
23:38:20 TRACE \[src/cpu.c:466\]: Instruction: 0x002D0202  
23:38:20 TRACE \[src/cpu.c:467\]: Opcode: 0b00000  
23:38:20 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:38:20 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:38:22 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:38:22 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:38:22 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:38:22 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:38:22 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:38:22 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:38:22 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:38:22 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción SRA desplaza correctamente los bits hacia la derecha preservando el bit de signo (extensión de signo). El resultado 0xFFFFFFFE (-2) es correcto para \-8 \>\> 2\.

**Caso \#16:**  
**Descripción:** Probar la instrucción SLLV (Shift Left Logical Variable) desplazando el valor en t3 (R\[11 \]= 12\) por la cantidad especificada t 3 (R\[11 \]= 12\) por cantidad especificada t4 (R\[12\] \= 3), almacenando el resultado en $t0 (R\[8\]).

**Cálculo esperado:**   
12 \= 0x0C \= 0000 1100  
12 \<\< 3 \= 0110 0000 \= 0x60 \= 96  
**Instrucciones utilizadas:** SLLV t0,t3,$t4  
**Formato R:** opcode | rs | rt | rd | aux | X | func  
**Instrucción completa:** 00000 01100 01011 01000 00000 0 000011  
**Hexadecimal:** 0x30B40003  
**Precondiciones:**

* R\[11\] \= 0x0000000C (12)  
* R\[12\] \= 0x00000003 (3)  
* PC \= 0x00000050

RTM32\> s PC 0x50  
Program Counter (PC) set to 0x00000050  
RTM32\> s \[0x50\] 0x30B40003  
RTM32\> n 1  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x00000060   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000054  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

* **R\[8\] \= 0x00000004** (12 ÷ 3 \= 4\)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **R\[12\] \= 0x00000003** (no modificado)  
* **PC \= 0x00000034**

23:44:04 DEBUG \[src/debug/execution.m:17\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000050  
23:44:04 TRACE \[src/cpu.c:245\]: RAM size: 0x00001000 read: 0x00000050  
23:44:04 TRACE \[src/cpu.c:466\]: Instruction: 0x30B40003  
23:44:04 TRACE \[src/cpu.c:467\]: Opcode: 0b00110  
23:44:04 TRACE \[src/opcodes/logical.m:10\]: \[XORI\] R26 (0x00000000) \= R2 (0x00000000) ^ 0x0003  
23:44:04 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.  
23:44:04 TRACE \[src/debug/debug.c:323\]: Entering blocking read on fd: 6  
23:44:05 TRACE \[src/debug/debug.c:329\]: Read returned n \= 3, errno \= 0 (Success)  
23:44:05 TRACE \[src/debug/debug.c:336\]: Buffer contents (HEX): 72 0D 0A   
23:44:05 TRACE \[src/debug/debug.c:269\]: \[1\] Finding command for: 'r'  
23:44:05 TRACE \[src/debug/debug.c:277\]: \[2\] Found command: 'registers'  
23:44:05 TRACE \[src/debug/debug.c:279\]: \[3\] Entering parse\_arguments for 'registers' with argc: 1  
23:44:05 TRACE \[src/debug/debug.c:168\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
23:44:05 TRACE \[src/debug/debug.c:285\]: \[4\] Invoking handler function pointer for 'registers'  
23:44:05 TRACE \[src/debug/debug.c:295\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción SLLV desplaza correctamente los bits hacia la izquierda por la cantidad especificada en el registro rs. El resultado 0x60 (96) es correcto para 12 \<\< 3\.

**Caso \#17:**  
**Descripción:** Probar la instrucción SW guardando el valor de t0 (R\[8\] \= 0x0000000F \= 15\) en la dirección de memoria calculada como (R\[11\] \= 0x0000000C) \+ 0\.

**Cálculo esperado:** 12 ÷ 3 \= 4 (cociente)  
**Instrucciones utilizadas:** SW t0,0(t3)  
**Formato I:** opcode | rs | rt | imm  
**Instrucción completa:** 01001 01011 01000 0000000000000000  
**Hexadecimal:** 0x4AD00000  
**Precondiciones:**

* R\[8\] \= 0x0000000F (15)  
* R\[11\] \= 0x0000000C (12)  
* PC \= 0x00000054

RTM32\> s PC 0x54  
Program Counter (PC) set to 0x00000054  
RTM32\> s \[0x54\] 0x4AD00000  
RTM32\> n 1  
Stepped instructions. Target PC: 0x00000058  
RTM32\> r  
\=== General Purpose Registers \===  
R\[ 0\]: 0x00000000   R\[ 1\]: 0x00000000   R\[ 2\]: 0x00000000   R\[ 3\]: 0x00000000  
R\[ 4\]: 0x00000000   R\[ 5\]: 0x00000000   R\[ 6\]: 0x00000000   R\[ 7\]: 0x00000000  
R\[ 8\]: 0x0000000F   R\[ 9\]: 0x00000000   R\[10\]: 0x00000000   R\[11\]: 0x0000000C  
R\[12\]: 0x00000003   R\[13\]: 0x00000000   R\[14\]: 0x00000000   R\[15\]: 0x00000000  
R\[16\]: 0x00000000   R\[17\]: 0x00000000   R\[18\]: 0x00000000   R\[19\]: 0x00000000  
R\[20\]: 0x00000000   R\[21\]: 0x00000000   R\[22\]: 0x00000000   R\[23\]: 0x00000000  
R\[24\]: 0x00000000   R\[25\]: 0x00000000   R\[26\]: 0x00000000   R\[27\]: 0x00000000  
R\[28\]: 0x00000000   R\[29\]: 0x00000000   R\[30\]: 0x00000000   R\[31\]: 0x00000000

\=== Control & Special Registers \===  
PC      : 0x00000058  CAUSE   : 0x00000000  EPC     : 0x00000000  
BADVADR : 0x00000000  VBR     : 0xF0000000

* **M\[0x0000000C\] \= 0x0000000F** (15 guardado correctamente)  
* **R\[8\] \= 0x0000000F** (no modificado)  
* **R\[11\] \= 0x0000000C** (no modificado)  
* **PC \= 0x00000058**

DEBUG \[23:52:48\]: Stepping CPU pipeline for 1 cycles. Current PC: 0x00000054  
TRACE \[23:52:48\]: RAM size: 0x00001000 read: 0x00000054  
TRACE \[23:52:48\]: Instruction: 0x4AD00000  
TRACE \[23:52:48\]: Opcode: 0b01001  
TRACE \[23:52:48\]: \[SW\] M\[0x0000000C\] \= R8 (0x0000000F)  
TRACE \[s23:52:48\]: \[5\] Handler finished execution successfully.  
TRACE \[23:52:52\]: \[ARG PARSER\] cmd-\>name='registers', cmd-\>min\_args=0, cmd-\>max\_args=0, cmd-\>fmt\_str=''  
TRACE \[23:52:52\]: \[4\] Invoking handler function pointer for 'registers'  
TRACE \[23:52:52\]: \[5\] Handler finished execution successfully.

**Conclusiones: Funciona** \- La instrucción SW guarda correctamente el valor del registro en la dirección de memoria calculada (EA \= R\[rs\] \+ imm). El valor 0x0000000F (15) se almacena correctamente en la dirección 0x0000000C.

[image1]: <data:image/png;base64,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>

[image2]: <data:image/png;base64,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>