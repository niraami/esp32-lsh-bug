idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS "include"
    REQUIRES ulp soc
)
component_compile_options(-std=gnu++17)

set(ulp_app_name		"ulp_prog")
set(ulp_s_sources		"ulp/ulp_prog.S")
set(ulp_exp_dep_srcs	"main.cpp")

ulp_embed_binary(${ulp_app_name} "${ulp_s_sources}" "${ulp_exp_dep_srcs}")
