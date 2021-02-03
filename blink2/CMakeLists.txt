add_executable(blink2
        blink2.c
)

target_link_libraries(blink2 pico_stdlib freertos)
pico_add_extra_outputs(blink2)
