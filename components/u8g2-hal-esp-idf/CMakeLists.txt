
set(COMPONENT_SRCDIRS
    "src"
)
set(COMPONENT_ADD_INCLUDEDIRS
    "include"
)
set(COMPONENT_REQUIRES
    driver
    freertos
    u8g2
)
set(COMPONENT_NAME ".")

register_component()