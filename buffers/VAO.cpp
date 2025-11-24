#include "VAO.h"
#include <glad/glad.h>

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

// ИСПРАВЛЕННАЯ ФУНКЦИЯ LinkVBO
void VAO::LinkVBO(VBO& VBO, GLuint layout, GLuint numComponents, GLsizeiptr stride, void* offset) {
    VBO.Bind(); // Привязываем VBO, чтобы VAO мог его "запомнить"


    glVertexAttribPointer(layout, numComponents, GL_FLOAT, GL_FALSE, stride, offset);
    
    glEnableVertexAttribArray(layout);
    VBO.Unbind(); // Отвязываем VBO
}

void VAO::Bind() {
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);
}