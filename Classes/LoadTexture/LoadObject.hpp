//
// Created by soham on 12/25/22.
//

#ifndef GAMECLION_LOADOBJECT_HPP
#define GAMECLION_LOADOBJECT_HPP

#include <cstring>
#include "../Libs/libs.hpp"

class LoadObject {
public:
    std::vector<glm::vec3> *out_vertices;
    std::vector<glm::vec2> out_uvs;
    std::vector<glm::vec3> out_normals;
    void loadObj(char *fname, GLuint *elem) {
        FILE *fp;
        int read;
        GLfloat x, y, z;
        char lineHeader[128];
        char ch;
        *elem = glGenLists(1);
        fp = fopen(fname, "r");
        if (!fp) {
            printf("can't open file %s\n", fname);
            exit(1);
        }
        glPointSize(2.0);
        glNewList(*elem, GL_COMPILE);
        {
            glPushMatrix();
            glBegin(GL_POINTS);
            while (!(feof(fp))) {
                read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
                if (read == EOF)
                    break;
                if (read == 4 && ch == 'v') {
                    glVertex3f(x, y, z);
                }
            }
            glEnd();
        }
        glPopMatrix();
        glEndList();
        fclose(fp);
    }

    struct Vertices{
        std::vector< glm::vec3 > vertices;
        std::vector< glm::vec2 > uvs;
        std::vector< glm::vec3 > normals;
    };

    bool loadOBJ(const char *path,std::vector< glm::vec3 > *vertices) {
        //struct Vertices *v = (struct Vertices*) std::malloc(sizeof(struct Vertices*));
        std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
        std::vector<glm::vec3> temp_vertices;
        std::vector<glm::vec2> temp_uvs;
        std::vector<glm::vec3> temp_normals;
        FILE *file = fopen(path, "r");
        if (file == NULL) {
            printf("Impossible to open the file !\n");
            return false;
        }
        while (1) {

            char lineHeader[128];
            // read the first word of the line
            int res = fscanf(file, "%s", lineHeader);
            if (res == EOF)
                break;
            if (strcmp(lineHeader, "v") == 0) {
                glm::vec3 vertex;
                fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
                vertices->push_back(vertex);
                //v->vertices.push_back(vertex);
                //free(v);
                //std::cout << temp_vertices[0][0];
            } else if (strcmp(lineHeader, "vt") == 0) {
                glm::vec2 uv;
                fscanf(file, "%f %f\n", &uv.x, &uv.y);
                //temp_uvs.push_back(uv);
            } else if (strcmp(lineHeader, "vn") == 0) {
                glm::vec3 normal;
                fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
                //temp_normals.push_back(normal);
            } else if (strcmp(lineHeader, "f") == 0) {
                std::string vertex1, vertex2, vertex3;
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0],
                                     &normalIndex[0],
                                     &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
                                     &normalIndex[2]);
                if (matches != 9) {
                    printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                    return false;
                }
//                vertexIndices.push_back(vertexIndex[0]);
//                vertexIndices.push_back(vertexIndex[1]);
//                vertexIndices.push_back(vertexIndex[2]);
//                uvIndices.push_back(uvIndex[0]);
//                uvIndices.push_back(uvIndex[1]);
//                uvIndices.push_back(uvIndex[2]);
//                normalIndices.push_back(normalIndex[0]);
//                normalIndices.push_back(normalIndex[1]);
//                normalIndices.push_back(normalIndex[2]);
            } else {
                //printf("Hii\n");
            }

            //std::cout<<temp_vertices[0][1];

        }
        //fclose(file);
//            for(  int i=0; i<=vertexIndices.size(); i++ ){
//                //cout<<"Hii\n";
//                glm::vec3 vertex = temp_vertices[i - 1];
//                //out_vertices.push_back(temp_vertices[i-1]);
//                cout<<vertex[i];
//            }
        //std::cout << vertexIndices.size();
    }
};

#endif //GAMECLION_LOADOBJECT_HPP
