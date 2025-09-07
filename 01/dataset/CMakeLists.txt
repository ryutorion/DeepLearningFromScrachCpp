add_library(
	mnist
	mnist.h
	mnist.cpp
)

target_include_directories(
	mnist
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(
	mnist
	PUBLIC -DMNIST_DATASET_PATH="${CMAKE_CURRENT_SOURCE_DIR}"
)
