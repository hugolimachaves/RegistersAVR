# registersAVR
Bibliotaca para acesso genericos a registradores AVR Versão 0.0.0.

## Como utilizar

+ Acessar determinado registrador através de seu código hexadecimal contido no datasheet do controlador
	- __Exemplo__ : 
		Para acessar o registrador PORTA do ATMEGA2560, passa o código (entre parenteses) desse registrador no datasheet.
		Nesse casso, consultando a tabela de registradores podemos ver que seu código é *0x22* (não confundir com 0x02)

+ Como os métodos são estáticos, __NÃO__ é necessário criar um objeto.