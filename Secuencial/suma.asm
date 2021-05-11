.data
dato1: 	.word 2 # Primer dato a comparar
dato2: 	.word 5 # Segundo dato a comparar
sum: 	.word 0 # Variable para almacenar la suma

.text
main: 	lw $8, dato1($0) # cargamos el primer dato en el registro $8
	lw $9, dato2($0) # cargamos el segundo dato en el registro $9
	add $10, $8, $9 # sumamos los registros y el resultado va a $10
	sw $10, sum($0) # almacenamos el resultado ($10) en sum

	move $4 $10
	li $2 1    
	syscall

fin: 	li $2, 10 # cargamos parámetro necesario para syscall
	syscall # llamada al sistema que termina un programa
