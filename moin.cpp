#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Inicializar GLFW
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW" << std::endl;
        return -1;
    }

    // Crear una ventana
    GLFWwindow* window = glfwCreateWindow(800, 600, "Mi primer proyecto OpenGL sin GLUT", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error al crear la ventana" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Inicializar GLEW
    glewInit();

    // Bucle principal
    while (!glfwWindowShouldClose(window)) {
        // Limpiar la pantalla
        glClear(GL_COLOR_BUFFER_BIT);

        // Dibuja aquí (por ejemplo, un triángulo)
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.0f, 0.5f);
        glEnd();

        // Intercambiar buffers y procesar eventos
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Limpiar y cerrar
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

