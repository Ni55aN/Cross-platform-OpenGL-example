#include <stdio.h>
#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>


GLFWwindow *window;

float red=0, green = 0., blue = 0;

void renderGame() {

	red+=0.005;
	green+=0.01;
	blue+=0.001;

	if(red>1.0)red=0.0;
	if(green>1.0)green=0.0;
	if(blue>1.0)blue=0.0;

	
	glClearColor(red,green,blue,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
  
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	printf("key_callback\n");
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
   printf("mouse_button_callback\n");
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	printf("cursor_position_callback\n");
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	printf("scroll_callback\n");
}


int main(){


   if (!glfwInit()) {
      printf("Failed to initialize GLFW3!\n");
       return 2;
   }

   window = glfwCreateWindow(640, 480, "Emscripten", NULL, NULL);

   if (!window) {
     printf("Failed to create GLFW3 window!\n");
       glfwTerminate();
       return 1;
   }


   glfwMakeContextCurrent(window);

   glfwSetKeyCallback(window, key_callback);
   glfwSetMouseButtonCallback(window, mouse_button_callback);
   glfwSetCursorPosCallback(window, cursor_position_callback);
   glfwSetScrollCallback(window, scroll_callback);

   printf("Emscripten app initialized\n");

   emscripten_set_main_loop(renderGame, 0, 0);
   
    return 0;
}

