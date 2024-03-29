#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>

#include "src/triangulo.h"
#include "src/exercicio01.h"



// Função para calcular o novo buffer para o tamanho da janela
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// Processa o input do teclado
void processInput(GLFWwindow* window);



int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_OPENGL_CORE_PROFILE);



	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Finalmente", NULL, NULL);
	if (window == NULL) {
		std::cout << "Problema em iniciar o GLFW!" << "\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);



	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Problema em iniciar o GLAD!" << "\n";
		return -1;
	}



	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



	int status_configuracao;

	// configurações dos arquivos
	// triangulo.h -> desenhar triangulo
	//configurarShader();

	// triangulo.h -> desenhar quadrado
	//configurarQuadrado();


	// exercicio 01
	configurar_exercicio01();
	status_configuracao = configurar_shaders_exercicio01();
	
	if (status_configuracao == -1) {
		glfwTerminate();
	}



	// loop principal de renderização
	while (!glfwWindowShouldClose(window)) {
		processInput(window);



		glClearColor(0.44f, 0.38f, 0.91f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		//desenharTriangulo();
		//desenharQuadrado();
		desenhar_exercicio01();



		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	limpar_exercicio01();



	glfwTerminate();
	return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}



void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
