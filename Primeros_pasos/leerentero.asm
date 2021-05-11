.data
saludo1: .asciiz "\n Leo un entero y lo escribo"
texto1: .asciiz " \nDame tu dni "

.text

main:
	li $2 4    #li $v0 4
	la $4 saludo1
	syscall
	
	la $4 texto1
	syscall
	
	
	li $2 5   #Lee entero de teclado y lo deja en v0 $2
	syscall
	
	move $4 $2  #Mueve para poder imprimir

	li $2 1 # muestra en pantalla lo leido
	syscall	
	
