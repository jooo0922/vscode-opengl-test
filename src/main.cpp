#include <iostream>
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main()
{
  // 앱 시작
  spdlog::info("Starting the application");

  // GLFW 초기화
  if (!glfwInit())
  {
    spdlog::error("Failed to initialize GLFW");
    return -1;
  }

  // GLFW 윈도우 설정 구성
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // GLFW 윈도우 생성
  spdlog::info("Create GLFW window");
  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);

  if (!window)
  {
    spdlog::error("Failed to create GLFW window");
    glfwTerminate();
    return -1;
  }

  // 렌더링 루프 실행
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
  }

  // GLFW 종료
  glfwTerminate();

  return 0;
}
