# /lib/CMakeLists.txt

# 정적 라이브러리 shape 를 만든다.
add_library(shape STATIC shape.cc)

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(shape PRIVATE -Wall -Werror)

include(FetchContent)
FetchContent_Declare(
  Fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "7.1.3"
)

FetchContent_MakeAvailable(Fmt)


target_link_libraries(shape PRIVATE pthread fmt)