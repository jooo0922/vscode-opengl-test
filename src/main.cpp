#include <iostream>
#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/** 콜백함수 선언 */

// GLFW 윈도우 resizing 콜백함수
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

// GLFW 윈도우 키 입력 콜백함수
void processInput(GLFWwindow *window);

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

  // 생성된 GLFW 윈도우 컨텍스트를 현재 OpenGL 컨텍스트로 등록
  glfwMakeContextCurrent(window);

  // GLFW 윈도우 resizing 콜백함수 등록
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // GLAD 를 사용하여 OpenGL 표준 API 호출 시 사용할 현재 그래픽 드라이버에 구현된 함수 포인터 런타임 로드
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    // 함수 포인터 로드 실패
    spdlog::error("Failed to initialized glad");
    return -1;
  }

  if (!window)
  {
    spdlog::error("Failed to create GLFW window");
    glfwTerminate();
    return -1;
  }

  // 색상 버퍼 초기화할 색상 변경
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

  // 렌더링 루프 실행
  while (!glfwWindowShouldClose(window))
  {
    // GLFW 윈도우 키 입력 감지
    processInput(window);

    // 색상 버퍼 초기화
    glClear(GL_COLOR_BUFFER_BIT);

    // Back 버퍼에 렌더링된 최종 이미지를 Front 버퍼에 교체 -> blinking 현상 방지
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // GLFW 종료 및 메모리 반납
  glfwTerminate();

  return 0;
}

/** 콜백함수 구현부 */

// GLFW 윈도우 resizing 콜백함수
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

// GLFW 윈도우 키 입력 콜백함수
void processInput(GLFWwindow *window)
{
  // ESC 키 입력 시 렌더링 루프 및 프로그램 종료
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}
