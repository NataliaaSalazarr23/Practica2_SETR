# Practica2_SETR
Práctica 2 de Sistemas embebidos en tiempo real

Emilio Hernández Santana 10095

Natalia Marian Salazar Domínguez 10073


## Preguntas

1. ¿Por qué es preferible pasar la configuración mediante pvParameters?
   
Porque permite reutilizar una sola función de tarea para varios canales, evitando duplicar código y mejorando la modularidad.

2. ¿Qué sucedería si task_params_t fuera local y no static?
   
La memoria dejaría de ser válida al salir de la función, provocando datos incorrectos o comportamientos inesperados en las tareas.

3. ¿Cuándo se nota la diferencia de prioridad entre tareas?
   
Cuando varias tareas están listas para ejecutarse al mismo tiempo; la de mayor prioridad se ejecuta primero.

4. ¿Por qué usar vTaskDelay() en lugar de un for de retardo?
   
Porque libera el procesador para que otras tareas puedan ejecutarse mientras espera.

5. ¿Qué esperarías del stack watermark?
    
Valores similares, ya que las tareas realizan prácticamente las mismas operaciones, aunque pueden existir pequeñas diferencias.

6. ¿Qué cambios se requieren para agregar un cuarto potenciómetro y LED?
    
Agregar un nuevo canal ADC, un nuevo canal PWM, una estructura task_params_t adicional y crear otra tarea con xTaskCreate(). No sería necesario modificar la función de tarea.


## Conclusión  

En esta práctica se desarrolló un sistema multitarea en el ESP32 utilizando FreeRTOS, donde tres tareas independientes leían el valor de tres potenciómetros mediante el ADC y controlaban el brillo de tres LEDs mediante señales PWM. Se aplicó el uso de pvParameters para reutilizar una sola función de tarea con diferentes configuraciones, logrando un código más modular y escalable. Como aprendizaje principal, se comprendió el funcionamiento básico del planificador de FreeRTOS, la creación de tareas, la lectura de entradas analógicas y el control de actuadores mediante PWM, además de la importancia de una correcta organización del código en módulos independientes.
