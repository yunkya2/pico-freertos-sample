add_executable(divcheck
        divcheck.c
)

target_link_libraries(divcheck pico_stdlib freertos)
pico_add_extra_outputs(divcheck)
