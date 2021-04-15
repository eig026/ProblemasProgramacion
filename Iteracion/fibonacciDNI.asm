# José Miguel Cazorla del Águila 76631393Q
# Obtener los n numeros de fibonacci 
# Requisitos:
#    El fichero ensamblador se tiene que llamar fibonacciDNI.s.
#    La función que calcula el término “n” de la sucesión se debe llamar “fib”
#    La función “fib” tomará un parámetro de entrada “n” que se le pasará a través del registro $2 y devolverá el resultado por el registro $4.
#    El valor de “n” debe ser igual al resto de dividir tu DNI por 20 y sumarle 9.
#    El programa fibonacciDNI.s tiene que imprimir el DNI y separados por comas el valor de n y el término “n” de la sucesión de Fibonacci.


.data
saludo1: .asciiz "\n  José Miguel Cazorla del Águila 76631393Q Ejercicio 5: Fundamentos de programación: curso 20-21"
texto1: .asciiz " \nDame tu dni (0 si no deseas dar valor) "
coma: .asciiz ", "
.text

main:

	li $2 4
	la $4 saludo1
	syscall
	la $4 texto1
	syscall
	li $5 76631393  #Carga inicial del DNI a5
	# Posibilidad de lectura interactiva del DNI	
	li $2 5  # para que se pueda leer un entero
	syscall
	beq $2 0 sig  #salta si se mantiene valor por defecto
	move $5 $2   #a5
sig:	
	move $4 $5  # para imprimir DNI	
	li $2 1
	syscall
	li $2 4
	la $4 coma
	syscall	
	
	move $4 $5  # de entrada dejo solo el $4 a mod4
	jal mod4
	move $6 $4   #preservo la n

	
	li $2 1
	syscall
	li $2 4
	la $4 coma
	syscall	
	
	move $2 $6  #por requisito de ejercicion entrada fib es $2
	jal fib
	

	li $2 1
	syscall
	j fin
	
mod4:	li $8 20
	div $4 $8 # divide lo que hay en a1 entre 20
 	mfhi $9 # resto a $a2
	subi $4 $9 9  
        jr $ra
        	
        
        
fib:	
	move $8 $2 # cantidad de numeros pedidos
	li $9 0 # cantidad de numeros mostrados
	li $10 1 # registro donde se guarda el actual
	li $11 0 # registro donde se guarda el anterior
	li $12 0 # registro temporal para copiar $t2 en $t3
	
loop:	beq $8 $9 exit
	
	move $12 $10
	add $10 $10 $11
	move $11 $12
	addi $9 $9 1
	b loop	
exit:   
	#la $4 coma
	#syscall
	move $4 $12 
	jr $ra	
	
fin:	li $2 10
	syscall
	
