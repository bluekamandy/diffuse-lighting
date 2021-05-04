// Calculate magnitude
// Light Direction: Ld = [0 1 0]
// Surface Color: kd = (0.1 0.1 0.5)
// Normals of 3 surface points:
// n1 = (0.4, 0.82, 0.4)
// n2 = (0.82, 0.4, 0.4)
// n3 = (0.2, 0.2, 0.9)

/*
         NORMAL ^         ^ LIGHT DIRECTION (Ld)
                |        /
                |      /
                |    /          VIEW is also important
                |  /
                |/
        ------------------ OBJECT SURFACE
*/

// DOT PRODUCT (Geometric Definition)
// vec2 u • vec2 v = ||u|| * ||v|| * cos(θ)

// DOT PRODUCT (Algebraic Definition)
// u • v = sum_i=1^n = u_i*v_i

// MAGNITUDE of a vector is sqrt(v_x * u_x + v_y * v_y)

// NORMALIZING a vector u_normalized = u / ||u||

// N = NORMAL
// L = LIGHT

// IF we normalize N and L
// N_norm • L_norm = cos(θ)

// cos θ is our light fall-off which is called diffuse reflection or diffuse coefficient (dCo)

// color = dCo * matDiff

#include <iostream>
#include <cmath>
#include <algorithm>
#include <glm/vec3.hpp>
//#include <glm/geometric.hpp>
#include <glm/gtx/string_cast.hpp>

#define LOG(msg) \
    std::cout << msg << std::endl

#define LOG_MATRIX(mat) \
    std::cout << glm::to_string(mat) << std::endl;

float dotProduct(glm::vec3 a, glm::vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float magnitude(glm::vec3 a)
{
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int main(int, char **)
{
    // PRACTICE
    glm::vec3 light(0.0, 1.0, 0.0);
    glm::vec3 matDiff(0.1, 0.1, 0.5);

    glm::vec3 normal_1(0.4, 0.82, 0.4);
    glm::vec3 normal_2(0.82, 0.4, 0.4);
    glm::vec3 normal_3(0.2, 0.2, 0.9);

    LOG("Normal 1 dCo");
    float dot_1 = glm::dot(normal_1, light);
    float dot_1_m = dotProduct(normal_1, light);
    LOG("GLM Dot = " << dot_1);
    LOG("My Dot = " << dot_1_m);
    LOG("Color 1 =");
    glm::vec3 color_1 = dot_1 * matDiff;
    LOG_MATRIX(color_1);

    LOG("Normal 2 dCo");
    float dot_2 = glm::dot(normal_2, light);
    LOG(dot_2);
    LOG("Color 2 =");
    glm::vec3 color_2 = dot_2 * matDiff;
    LOG_MATRIX(color_2);

    LOG("Normal 3 dCo");
    float dot_3 = glm::dot(normal_3, light);
    LOG(dot_3);
    LOG("Color 3 =");
    glm::vec3 color_3 = dot_3 * matDiff;
    LOG_MATRIX(color_3);

    // QUIZ

    // Equation given is Kd * (max(0, (N•L)))

    glm::vec3 material_diffuse(0.1, 0.2, 0.2);

    glm::vec3 light_position(-10, 5, -10);

    glm::vec3 point_position(-2, 1, -1);

    glm::vec3 point_normal(-6, 0, 8);

    glm::vec3 light_vector = light_position - point_position;

    LOG("L = Vector from point to light = < light - point > = " << glm::to_string(light_vector));

    glm::vec3 point_normal_normalized = point_normal / magnitude(point_normal);

    LOG("norm(N) = " << glm::to_string(point_normal_normalized));

    glm::vec3 light_vector_normalized = light_vector / magnitude(light_vector);

    LOG("norm(L) = " << glm::to_string(light_vector_normalized));

    float ndotl = dotProduct(point_normal_normalized, light_vector_normalized);

    LOG("N • L = " << ndotl);

    glm::vec3 reflected_color = material_diffuse * (std::max(0.0f, ndotl));

    LOG("Reflected color is " << glm::to_string(reflected_color));
}
