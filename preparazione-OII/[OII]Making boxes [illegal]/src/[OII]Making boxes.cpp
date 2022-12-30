#include <iostream>
using namespace std;




int boxes[5001] = {4, 6, 8, 8, 12, 10, 14, 12, 12, 14, 18, 14, 18, 18, 16, 16, 20, 18, 22, 18, 20, 24, 26, 20, 20, 24, 24, 22, 26, 22, 26, 24, 28, 30, 24, 24, 28, 30, 32, 26, 30, 26, 30, 30, 28, 32, 34, 28, 28, 30, 34, 34, 36, 30, 32, 30, 34, 36, 38, 32, 36, 38, 32, 32, 36, 34, 38, 40, 42, 34, 38, 34, 38, 40, 40, 42, 36, 38, 42, 36, 36, 40, 42, 38, 42, 44, 46, 38, 42, 38, 40, 44, 46, 46, 48, 40, 44, 42, 40, 40, 44, 46, 48, 42, 44, 48, 50, 42, 46, 42, 46, 44, 48, 50, 52, 52, 44, 48, 48, 44, 44, 48, 50, 52, 52, 46, 50, 48, 52, 46, 50, 46, 50, 52, 48, 50, 54, 56, 56, 48, 52, 54, 48, 48, 52, 54, 56, 56, 58, 50, 54, 54, 52, 50, 54, 50, 54, 56, 58, 52, 56, 54, 58, 60, 52, 56, 58, 52, 52, 54, 56, 60, 60, 62, 62, 54, 58, 60, 62, 54, 58, 54, 58, 60, 62, 62, 56, 60, 60, 58, 62, 56, 60, 62, 56, 56, 60, 58, 62, 60, 64, 66, 68, 58, 62, 64, 64, 58, 60, 58, 62, 64, 66, 66, 70, 60, 64, 66, 68, 62, 60, 64, 66, 60, 60, 64, 66, 62, 66, 66, 64, 68, 70, 62, 66, 68, 70, 62, 66, 62, 66, 66, 70, 70, 74, 72, 64, 68, 70, 70, 72, 64, 68, 70, 64, 64, 68, 70, 72, 66, 70, 72, 74, 68, 72, 66, 70, 72, 74, 66, 70, 66, 68, 72, 72, 70, 74, 76, 78, 68, 72, 74, 76, 76, 68, 70, 74, 68, 68, 72, 74, 76, 76, 70, 74, 76, 76, 78, 72, 70, 74, 76, 78, 70, 74, 70, 74, 72, 76, 78, 80, 74, 78, 80, 72, 76, 78, 80, 80, 72, 76, 74, 72, 72, 76, 78, 80, 80, 82, 74, 78, 80, 82, 82, 86, 74, 78, 78, 82, 74, 78, 74, 78, 80, 76, 80, 82, 82, 84, 78, 80, 76, 80, 82, 84, 84, 76, 80, 82, 76, 76, 80, 82, 80, 84, 86, 86, 78, 82, 84, 86, 86, 90, 78, 80, 84, 84, 78, 82, 78, 82, 84, 86, 80, 84, 86, 88, 88, 90, 82, 80, 84, 86, 88, 88, 80, 84, 86, 80, 80, 84, 86, 88, 88, 84, 86, 90, 82, 86, 88, 90, 90, 94, 82, 86, 84, 88, 82, 86, 82, 86, 88, 90, 90, 84, 88, 90, 92, 92, 96, 94, 84, 88, 90, 88, 92, 84, 88, 90, 84, 84, 86, 90, 92, 92, 94, 94, 88, 92, 86, 90, 92, 94, 94, 96, 86, 90, 92, 88, 86, 90, 86, 90, 90, 92, 94, 98, 88, 92, 94, 96, 96, 100, 98, 88, 90, 94, 96, 96, 88, 92, 94, 88, 88, 92, 90, 94, 96, 98, 98, 100, 100, 92, 90, 94, 94, 98, 98, 102, 90, 94, 96, 98, 90, 94, 90, 94, 96, 98, 94, 98, 96, 92, 96, 98, 100, 100, 102, 102, 92, 96, 94, 98, 100, 92, 96, 96, 92, 92, 96, 98, 94, 98, 100, 102, 102, 104, 104, 106, 94, 98, 100, 102, 98, 102, 94, 98, 100, 102, 94, 96, 94, 98, 100, 102, 102, 106, 98, 102, 96, 100, 102, 104, 104, 108, 106, 96, 100, 102, 98, 102, 96, 100, 102, 96, 96, 100, 102, 104, 98, 102, 104, 106, 106, 108, 108, 110, 98, 100, 104, 106, 106, 108, 98, 102, 104, 106, 98, 102, 98, 102, 104, 106, 106, 110, 108, 110, 102, 100, 104, 106, 104, 108, 110, 110, 100, 104, 106, 108, 102, 100, 104, 106, 100, 100, 104, 104, 108, 108, 102, 106, 108, 110, 110, 114, 112, 114, 102, 106, 104, 108, 110, 112, 102, 106, 106, 110, 102, 106, 102, 104, 108, 110, 110, 112, 112, 114, 114, 114, 104, 108, 110, 112, 112, 108, 110, 104, 108, 110, 112, 112, 104, 108, 110, 104, 104, 108, 110, 112, 108, 112, 106, 110, 110, 114, 114, 118, 116, 120, 106, 110, 112, 108, 112, 114, 106, 110, 112, 114, 106, 110, 106, 110, 108, 112, 114, 116, 116, 118, 118, 118, 120, 108, 110, 114, 116, 116, 118, 118, 108, 112, 114, 116, 116, 108, 110, 114, 108, 108, 112, 114, 116, 116, 118, 112, 110, 114, 116, 118, 114, 116, 120, 122, 110, 114, 116, 118, 112, 116, 110, 114, 116, 118, 110, 114, 110, 114, 116, 112, 116, 118, 120, 120, 122, 122, 124, 124, 112, 116, 114, 118, 120, 122, 122, 112, 116, 116, 120, 120, 112, 116, 114, 112, 112, 116, 118, 120, 120, 122, 122, 124, 114, 118, 120, 122, 122, 126, 118, 122, 114, 118, 120, 122, 122, 116, 114, 118, 120, 122, 114, 118, 114, 118, 118, 122, 116, 120, 122, 120, 122, 126, 126, 128, 128, 116, 120, 122, 118, 122, 124, 126, 116, 120, 122, 124, 120, 116, 120, 122, 116, 116, 120, 122, 124, 124, 126, 126, 128, 128, 118, 120, 124, 126, 126, 128, 128, 130, 118, 122, 124, 124, 126, 130, 118, 122, 124, 126, 118, 122, 118, 122, 124, 126, 122, 120, 124, 126, 128, 128, 124, 128, 126, 130, 120, 124, 126, 128, 122, 126, 128, 120, 124, 126, 128, 128, 120, 124, 126, 120, 120, 124, 126, 128, 128, 130, 130, 132, 132, 132, 122, 126, 124, 128, 130, 132, 132, 136, 122, 126, 126, 130, 130, 134, 122, 124, 128, 130, 122, 126, 122, 126, 128, 130, 130, 134, 124, 128, 130, 132, 132, 136, 134, 128, 132, 124, 128, 130, 132, 132, 126, 130, 124, 128, 130, 132, 132, 124, 128, 130, 124, 124, 126, 130, 132, 132, 130, 134, 132, 136, 136, 138, 126, 130, 132, 128, 132, 134, 136, 136, 126, 130, 132, 134, 130, 134, 126, 130, 128, 132, 126, 130, 126, 130, 132, 134, 134, 138, 136, 128, 130, 134, 136, 136, 138, 138, 140, 140, 128, 132, 134, 136, 134, 138, 130, 128, 132, 134, 136, 136, 128, 132, 134, 128, 128, 132, 130, 134, 136, 138, 138, 140, 134, 138, 138, 136, 130, 134, 136, 138, 132, 136, 138, 140, 130, 134, 136, 138, 138, 142, 130, 134, 136, 132, 130, 134, 130, 134, 136, 138, 138, 142, 140, 142, 132, 136, 134, 138, 140, 142, 142, 144, 144, 132, 136, 136, 140, 140, 142, 142, 132, 136, 138, 140, 140, 132, 136, 138, 132, 132, 136, 138, 134, 138, 140, 142, 142, 144, 144, 146, 138, 142, 134, 138, 140, 142, 142, 136, 140, 142, 134, 138, 140, 142, 142, 146, 134, 138, 138, 142, 134, 138, 134, 138, 140, 140, 142, 144, 142, 146, 146, 136, 140, 142, 138, 142, 144, 146, 146, 148, 136, 140, 142, 144, 140, 144, 146, 136, 138, 142, 142, 144, 136, 140, 142, 136, 136, 140, 142, 144, 138, 140, 144, 146, 146, 148, 148, 150, 150, 150, 138, 142, 144, 146, 146, 144, 140, 144, 138, 142, 144, 146, 146, 150, 138, 142, 144, 146, 138, 140, 138, 142, 144, 146, 146, 150, 144, 148, 150, 150, 140, 144, 146, 148, 142, 146, 148, 150, 150, 140, 144, 146, 148, 148, 152, 144, 140, 144, 142, 146, 148, 140, 144, 146, 140, 140, 144, 146, 148, 148, 142, 146, 144, 148, 150, 152, 152, 154, 154, 154, 142, 146, 146, 150, 150, 154, 152, 144, 142, 146, 148, 150, 150, 154, 142, 146, 148, 150, 142, 146, 142, 146, 148, 150, 150, 154, 152, 154, 154, 148, 152, 144, 148, 150, 150, 152, 146, 150, 152, 154, 144, 148, 150, 152, 152, 156, 154, 144, 148, 150, 146, 150, 144, 148, 150, 144, 144, 148, 150, 152, 152, 154, 146, 150, 152, 148, 152, 154, 156, 156, 158, 158, 146, 150, 152, 154, 150, 154, 156, 158, 146, 150, 152, 152, 154, 156, 146, 150, 152, 154, 146, 150, 146, 148, 150, 154, 154, 156, 156, 158, 158, 158, 160, 162, 148, 152, 154, 156, 156, 160, 150, 154, 156, 148, 152, 154, 156, 156, 160, 158, 148, 152, 154, 152, 150, 148, 152, 154, 148, 148, 152, 154, 154, 156, 158, 158, 150, 154, 156, 158, 152, 156, 158, 160, 160, 162, 150, 154, 156, 158, 158, 162, 154, 158, 150, 152, 156, 158, 158, 160, 150, 154, 156, 158, 150, 154, 150, 154, 152, 156, 154, 158, 160, 162, 162, 162, 164, 164, 164, 152, 156, 156, 160, 160, 164, 162, 154, 158, 152, 156, 158, 160, 160, 164, 162, 152, 156, 158, 160, 160, 152, 156, 158, 152, 152, 156, 158, 160, 160, 162, 158, 162, 154, 158, 160, 162, 160, 156, 160, 162, 164, 164, 154, 158, 160, 162, 162, 166, 164, 168, 154, 158, 156, 160, 162, 164, 154, 158, 160, 160, 154, 158, 154, 158, 160, 156, 160, 162, 158, 162, 164, 166, 166, 168, 168, 170, 156, 160, 162, 164, 160, 164, 166, 168, 158, 156, 160, 162, 162, 164, 168, 166, 156, 160, 162, 164, 164, 156, 158, 160, 156, 156, 160, 162, 164, 164, 166, 166, 168, 168, 158, 162, 164, 166, 166, 170, 160, 164, 166, 168, 158, 162, 164, 166, 166, 170, 168, 172, 158, 162, 162, 160, 164, 166, 158, 162, 164, 166, 158, 162, 158, 162, 164, 166, 160, 164, 166, 168, 162, 166, 168, 170, 170, 172, 172, 160, 164, 166, 168, 168, 172, 164, 168, 170, 160, 164, 166, 168, 168, 172, 166, 160, 164, 166, 168, 168, 160, 164, 162, 160, 160, 164, 166, 168, 168, 170, 170, 172, 172, 172, 162, 166, 166, 170, 170, 174, 172, 164, 168, 170, 162, 166, 168, 170, 170, 174, 172, 176, 162, 166, 168, 170, 164, 168, 162, 166, 168, 170, 162, 166, 162, 166, 168, 168, 170, 164, 168, 170, 172, 172, 166, 170, 172, 172, 174, 178, 164, 168, 170, 172, 172, 176, 174, 178, 168, 164, 166, 170, 172, 172, 174, 174, 164, 168, 170, 172, 172, 164, 168, 170, 164, 164, 168, 168, 172, 172, 174, 174, 176, 176, 176, 178, 166, 170, 172, 174, 170, 174, 176, 178, 168, 172, 166, 170, 172, 172, 174, 178, 176, 180, 166, 170, 172, 174, 174, 168, 166, 170, 172, 174, 166, 170, 166, 170, 172, 174, 174, 178, 168, 172, 174, 176, 176, 180, 170, 174, 174, 178, 178, 168, 172, 174, 176, 176, 180, 178, 182, 180, 168, 172, 170, 174, 176, 178, 178, 168, 172, 174, 176, 176, 168, 172, 174, 168, 168, 172, 174, 176, 172, 176, 178, 180, 180, 180, 182, 182, 170, 174, 176, 178, 178, 182, 174, 178, 180, 172, 170, 174, 176, 178, 178, 182, 176, 180, 170, 174, 176, 178, 178, 182, 170, 174, 174, 178, 170, 174, 170, 174, 176, 178, 178, 182, 180, 172, 176, 176, 180, 180, 184, 182, 174, 178, 180, 182, 172, 176, 178, 180, 180, 180, 182, 186, 184, 172, 176, 178, 174, 178, 180, 182, 172, 176, 178, 180, 180, 172, 176, 178, 172, 172, 174, 178, 180, 180, 182, 176, 180, 182, 184, 184, 182, 186, 174, 178, 180, 182, 182, 186, 184, 188, 178, 182, 174, 178, 180, 182, 182, 186, 184, 188, 174, 178, 180, 182, 182, 186, 174, 176, 180, 182, 174, 178, 174, 178, 180, 182, 182, 186, 184, 186, 176, 180, 182, 184, 180, 184, 186, 188, 178, 182, 184, 176, 180, 182, 182, 184, 188, 186, 190, 188, 176, 180, 182, 184, 178, 180, 184, 176, 180, 182, 184, 184, 176, 180, 182, 176, 176, 180, 178, 182, 184, 186, 186, 188, 180, 184, 186, 184, 188, 190, 178, 182, 184, 186, 186, 190, 188, 192, 190, 190, 178, 180, 184, 186, 186, 188, 188, 190, 178, 182, 184, 186, 184, 188, 178, 182, 180, 184, 178, 182, 178, 182, 184, 186, 186, 190, 188, 190, 190, 180, 184, 186, 188, 188, 192, 184, 188, 190, 182, 186, 180, 184, 186, 188, 188, 192, 186, 190, 192, 180, 184, 186, 188, 188, 182, 186, 180, 184, 186, 188, 188, 180, 184, 186, 180, 180, 184, 186, 182, 186, 186, 190, 190, 192, 192, 184, 188, 190, 192, 192, 182, 186, 188, 190, 190, 194, 190, 194, 192, 194, 182, 186, 184, 188, 190, 192, 192, 196, 182, 186, 188, 190, 190, 194, 182, 186, 188, 184, 182, 186, 182, 186, 186, 190, 190, 194, 192, 194, 194, 192, 184, 188, 190, 192, 192, 196, 194, 198, 188, 192, 186, 184, 188, 190, 192, 192, 196, 194, 198, 196, 184, 188, 190, 192, 192, 196, 186, 184, 188, 188, 192, 192, 184, 188, 190, 184, 184, 188, 190, 192, 186, 190, 192, 194, 190, 194, 196, 198, 188, 192, 194, 196, 186, 190, 192, 192, 194, 198, 196, 200, 198, 198, 186, 190, 192, 188, 190, 194, 196, 196, 186, 190, 192, 194, 194, 198, 186, 190, 192, 194, 186, 190, 186, 190, 192, 194, 190, 194, 196, 198, 194, 198, 200, 188, 192, 194, 196, 196, 198, 198, 202, 200, 200, 192, 188, 192, 194, 196, 196, 200, 198, 202, 200, 188, 192, 194, 194, 196, 200, 198, 188, 192, 194, 196, 192, 188, 192, 194, 188, 188, 192, 194, 196, 196, 190, 194, 196, 198, 198, 202, 194, 198, 200, 192, 196, 198, 190, 194, 196, 198, 198, 202, 196, 200, 202, 202, 190, 194, 196, 198, 192, 196, 194, 198, 190, 194, 196, 198, 198, 202, 190, 194, 196, 198, 190, 192, 190, 194, 196, 198, 198, 202, 194, 198, 200, 202, 202, 206, 192, 196, 198, 200, 200, 204, 202, 200, 204, 204, 202, 192, 194, 198, 200, 200, 202, 202, 204, 204, 192, 196, 198, 200, 200, 204, 198, 192, 194, 198, 200, 200, 192, 196, 198, 192, 192, 196, 198, 200, 200, 202, 194, 198, 200, 202, 202, 206, 204, 208, 198, 202, 196, 200, 194, 198, 200, 202, 202, 206, 204, 208, 206, 200, 194, 198, 200, 202, 202, 196, 200, 202, 194, 198, 200, 202, 202, 204, 194, 198, 200, 202, 194, 198, 194, 198, 200, 202, 200, 204, 204, 206, 198, 202, 204, 206, 206, 196, 200, 202, 202, 204, 208, 206, 210, 208, 208, 210, 196, 200, 198, 200, 204, 206, 206, 208, 208, 196, 200, 202, 204, 204, 208, 206, 196, 200, 198, 202, 204, 196, 200, 202, 196, 196, 200, 202, 204, 204, 206, 206, 198, 202, 204, 206, 206, 210, 208, 208, 210, 210, 202, 200, 198, 202, 204, 206, 206, 210, 208, 212, 210, 210, 198, 202, 204, 206, 206, 210, 200, 204, 198, 202, 202, 206, 206, 210, 198, 202, 204, 206, 198, 202, 198, 200, 204, 206, 206, 208, 208, 204, 208, 210, 202, 206, 208, 210, 200, 204, 206, 208, 208, 212, 206, 210, 212, 212, 214, 200, 204, 206, 202, 206, 204, 208, 210, 212, 200, 204, 206, 208, 208, 212, 210, 200, 204, 206, 202, 206, 200, 204, 206, 200, 200, 204, 206, 208, 208, 210, 210, 212, 202, 206, 208, 210, 210, 214, 212, 216, 210, 214, 216, 218, 202, 206, 208, 210, 210, 214, 212, 216, 214, 214, 202, 206, 208, 210, 210, 208, 212, 204, 202, 206, 208, 210, 206, 210, 202, 206, 208, 210, 202, 206, 202, 206, 204, 208, 210, 212, 212, 214, 214, 214, 208, 212, 206, 210, 212, 204, 208, 210, 212, 212, 216, 214, 218, 216, 210, 214, 204, 208, 210, 212, 206, 210, 212, 208, 212, 204, 208, 210, 212, 212, 214, 214, 204, 208, 210, 212, 206, 204, 208, 210, 204, 204, 208, 210, 208, 212, 214, 214, 216, 216, 206, 210, 212, 212, 214, 218, 216, 220, 218, 218, 220, 222, 206, 208, 210, 214, 214, 216, 216, 218, 218, 218, 206, 210, 212, 214, 214, 218, 216, 220, 206, 210, 212, 214, 214, 218, 206, 210, 212, 214, 206, 210, 206, 210, 212, 208, 212, 214, 216, 216, 216, 218, 220, 220, 218, 212, 210, 214, 208, 212, 214, 216, 216, 220, 218, 222, 220, 220, 222, 208, 212, 214, 216, 216, 210, 214, 216, 218, 208, 212, 214, 216, 216, 220, 218, 208, 212, 214, 216, 216, 208, 212, 214, 208, 208, 212, 214, 216, 216, 212, 216, 218, 220, 220, 210, 214, 216, 218, 218, 222, 216, 220, 222, 222, 224, 228, 210, 214, 212, 216, 214, 218, 220, 222, 222, 222, 210, 214, 216, 218, 218, 222, 220, 224, 210, 212, 216, 216, 218, 220, 210, 214, 214, 218, 210, 214, 210, 214, 216, 218, 212, 216, 218, 220, 220, 222, 222, 226, 224, 220, 224, 226, 214, 212, 216, 218, 220, 220, 224, 222, 226, 224, 224, 226, 212, 216, 218, 220, 218, 222, 214, 218, 220, 212, 216, 216, 220, 220, 224, 222, 212, 216, 218, 220, 220, 212, 214, 218, 212, 212, 216, 218, 220, 220, 218, 222, 216, 220, 222, 224, 214, 218, 220, 222, 222, 226, 224, 228, 226, 220, 224, 226, 214, 218, 220, 216, 220, 222, 218, 222, 222, 226, 214, 218, 220, 222, 222, 224, 224, 228, 214, 218, 216, 220, 222, 224, 214, 218, 220, 222, 214, 218, 214, 218, 220, 222, 222, 216, 220, 222, 222, 224, 228, 226, 228, 228, 228, 230, 230, 230, 216, 220, 222, 224, 224, 228, 226, 230, 228, 228, 230, 216, 220, 222, 224, 224, 228, 226, 218, 222, 216, 220, 222, 224, 220, 224, 226, 216, 220, 222, 224, 224, 216, 220, 218, 216, 216, 220, 222, 224, 224, 226, 226, 228, 222, 220, 224, 226, 218, 222, 224, 226, 226, 230, 228, 232, 230, 230, 232, 236, 218, 222, 224, 226, 220, 224, 226, 228, 222, 226, 218, 222, 224, 226, 226, 230, 228, 232, 218, 222, 224, 220, 224, 226, 218, 222, 224, 224, 218, 222, 218, 222, 224, 226, 226, 230, 220, 224, 226, 228, 228, 232, 226, 230, 232, 232, 234, 238, 234, 220, 222, 226, 224, 228, 230, 230, 232, 232, 232, 234, 220, 224, 226, 228, 228, 232, 230, 234, 222, 220, 224, 226, 228, 228, 232, 224, 220, 224, 226, 228, 228, 220, 224, 226, 220, 220, 224, 226, 228, 228, 230, 230, 232, 232, 230, 234, 224, 228, 222, 226, 228, 230, 230, 234, 232, 236, 234, 234, 236, 240, 222, 226, 228, 228, 230, 224, 228, 230, 232, 232, 222, 226, 228, 230, 230, 234, 230, 234, 222, 226, 228, 230, 224, 228, 222, 226, 228, 230, 222, 226, 222, 226, 226, 230, 230, 234, 232, 224, 228, 230, 232, 232, 236, 234, 238, 236, 230, 234, 236, 238, 224, 228, 226, 230, 232, 228, 232, 234, 232, 236, 238, 224, 228, 230, 232, 232, 234, 234, 238, 236, 224, 228, 230, 232, 230, 234, 234, 224, 228, 230, 232, 232, 224, 228, 230, 224, 224, 228, 230, 232, 232, 234, 234, 236, 236, 236, 238, 238, 238, 228, 226, 230, 232, 234, 234, 238, 236, 236, 238, 238, 238, 242, 226, 230, 232, 234, 234, 238, 228, 232, 234, 236, 226, 230, 230, 234, 234, 238, 236, 240, 226, 230, 232, 234, 234, 228, 226, 230, 232, 234, 226, 230, 226, 230, 232, 232, 230, 234, 236, 238, 228, 232, 234, 236, 236, 240, 238, 242, 240, 240, 242, 246, 234, 228, 232, 234, 230, 234, 236, 238, 232, 236, 238, 240, 228, 232, 234, 236, 236, 240, 238, 242, 240, 228, 230, 234, 236, 236, 238, 238, 228, 232, 234, 232, 236, 228, 232, 234, 228, 228, 230, 234, 236, 236, 238, 238, 236, 240, 240, 242, 242, 242, 244, 244, 230, 234, 234, 238, 238, 242, 240, 244, 242, 242, 244, 246, 230, 234, 236, 238, 238, 242, 240, 232, 236, 236, 230, 234, 236, 238, 234, 238, 240, 242, 230, 234, 236, 238, 238, 242, 230, 234, 236, 238, 230, 234, 230, 234, 236, 238, 238, 240, 234, 238, 240, 232, 236, 238, 240, 240, 244, 242, 246, 244, 244, 246, 248, 246, 232, 236, 238, 240, 234, 238, 240, 242, 242, 236, 240, 232, 236, 238, 240, 240, 240, 242, 246, 244, 232, 236, 234, 238, 240, 242, 242, 232, 236, 238, 238, 240, 232, 236, 238, 232, 232, 236, 234, 238, 240, 242, 242, 244, 244, 244, 246, 240, 244, 246, 248, 248, 234, 236, 240, 242, 238, 242, 244, 246, 242, 246, 248, 250, 234, 238, 240, 242, 242, 244, 244, 248, 236, 240, 234, 238, 240, 242, 242, 246, 238, 242, 234, 238, 240, 242, 242, 246, 234, 236, 240, 242, 234, 238, 234, 238, 240, 242, 242, 246, 244, 246, 238, 240, 236, 240, 242, 244, 244, 248, 246, 250, 246, 248, 250, 254, 248, 236, 240, 242, 244, 244, 238, 242, 244, 246, 246, 250, 236, 240, 242, 244, 244, 248, 246, 250, 248, 236, 240, 242, 238, 242, 244, 246, 236, 240, 242, 244, 244, 236, 240, 240, 236, 236, 240, 242, 238, 242, 244, 246, 246, 248, 248, 250, 250, 250, 252, 252, 244, 248, 238, 242, 240, 244, 246, 248, 242, 246, 248, 250, 250, 252, 238, 242, 244, 246, 246, 250, 248, 252, 250, 240, 238, 242, 244, 246, 246, 244, 248, 250, 238, 242, 244, 246, 246, 250, 238, 242, 240, 244, 238, 242, 238, 242, 244, 246, 246, 250, 248, 250, 250, 250, 242, 240, 244, 246, 248, 248, 252, 250, 254, 252, 252, 254, 256, 254, 240, 244, 246, 248, 248, 252, 242, 246, 246, 250, 250, 240, 244, 244, 248, 248, 252, 250, 254, 252, 240, 244, 246, 248, 242, 246, 248, 240, 244, 246, 248, 248, 240, 244, 246, 240, 240, 244, 246, 248, 242, 246, 248, 250, 250, 252, 252, 254, 254, 254, 256, 256, 256, 258, 242, 246, 248, 244, 248, 250, 252, 252, 246, 250, 252, 254, 242, 246, 248, 250, 250, 254, 252, 256, 254, 254, 242, 246, 248, 250, 250, 252, 252, 256, 242, 246, 246, 250, 250, 254, 242, 246, 248, 244, 242, 246, 242, 246, 248, 250, 250, 254, 250, 254, 254, 254, 256, 260, 244, 248, 250, 248, 252, 254, 254, 256, 252, 256, 258, 260, 258, 244, 248, 250, 252, 252, 254, 254, 246, 250, 252, 254, 244, 248, 250, 252, 248, 252, 254, 256, 256, 244, 248, 250, 252, 252, 246, 250, 244, 248, 250, 252, 252, 244, 248, 250, 244, 244, 248, 248, 250, 252, 246, 250, 252, 254, 254, 258, 256, 258, 258, 256, 260, 260, 260, 262, 246, 250, 252, 254, 248, 252, 254, 256, 256, 258, 250, 254, 246, 250, 252, 254, 254, 258, 256, 260, 254, 258, 246, 248, 252, 254, 254, 256, 256, 258, 246, 250, 252, 252, 250, 254, 246, 250, 252, 254, 246, 250, 246, 250, 252, 254, 254, 258, 256, 258, 258, 258, 254, 258, 260, 248, 250, 254, 256, 256, 252, 256, 258, 260, 260, 262, 262, 256, 248, 252, 254, 256, 256, 260, 258, 262, 250, 254, 256, 248, 252, 254, 254, 256, 260, 252, 256, 258, 248, 252, 254, 256, 256, 260, 250, 248, 252, 254, 256, 256, 248, 252, 254, 248, 248, 252, 254, 256, 252, 256, 250, 254, 256, 258, 258, 262, 260, 264, 262, 262, 264, 266, 264, 266, 250, 254, 256, 258, 258, 252, 256, 256, 260, 260, 264, 262, 250, 254, 256, 258, 258, 262, 260, 264, 262, 262, 250, 254, 252, 256, 258, 260, 260, 264, 250, 254, 256, 258, 258, 262, 250, 254, 256, 258, 250, 252, 250, 254, 256, 258, 258, 262, 260, 262, 262, 262, 264, 266, 264, 266, 252, 256, 254, 258, 260, 262, 262, 256, 260, 262, 264, 264, 266, 252, 256, 258, 260, 260, 264, 262, 266, 264, 254, 258, 252, 256, 258, 260, 260, 264, 258, 262, 256, 252, 256, 258, 260, 260, 264, 262, 252, 256, 258, 260, 260, 252, 256, 258, 252, 252, 256, 258, 260, 260, 262, 256, 254, 258, 258, 262, 262, 266, 264, 268, 262, 266, 268, 270, 268, 270, 254, 258, 260, 262, 262, 264, 256, 260, 262, 264, 260, 264, 254, 258, 258, 262, 262, 266, 264, 268, 266, 266, 254, 258, 260, 256, 260, 262, 262, 264, 254, 258, 260, 262, 262, 266, 254, 258, 258, 260, 254, 258, 254, 258, 260, 262, 262, 266, 264, 266, 266, 266, 266, 270, 268, 270, 270, 256, 260, 262, 258, 262, 264, 266, 266, 268, 260, 264, 266, 268, 256, 260, 262, 264, 264, 268, 266, 264, 268, 268, 258, 256, 260, 262, 264, 264, 268, 266, 270, 268, 256, 260, 262, 264, 264, 268, 266, 256, 258, 262, 264, 264, 256, 260, 262, 256, 256, 260, 262, 264, 264, 266, 266, 268, 258, 262, 264, 266, 262, 266, 268, 270, 270, 270, 272, 274, 266, 270, 258, 262, 264, 266, 266, 270, 268, 260, 264, 266, 268, 268, 258, 262, 264, 266, 262, 266, 268, 270, 270, 270, 258, 262, 264, 266, 260, 264, 266, 268, 258, 262, 264, 266, 266, 270, 258, 262, 264, 266, 258, 262, 258, 260, 264, 266, 266, 268, 268, 270, 270, 270, 272, 274, 272, 274, 274, 274, 260, 264, 266, 268, 262, 266, 266, 270, 270, 272, 272, 264, 268, 260, 264, 266, 268, 268, 272, 270, 274, 272, 272, 274, 260, 264, 266, 268, 268, 272, 270, 274, 272, 260, 264, 266, 264, 268, 270, 270, 260, 264, 262, 266, 268, 260, 264, 266, 260, 260, 264, 266, 268, 268, 270, 270, 272, 268, 262, 264, 268, 270, 270, 272, 266, 270, 272, 274, 274, 278, 276, 278, 262, 266, 268, 270, 270, 274, 272, 276, 264, 268, 270, 272, 262, 266, 268, 270, 268, 272, 266, 270, 272, 274, 262, 266, 268, 270, 270, 264, 268, 270, 262, 266, 268, 270, 270, 274, 262, 266, 268, 270, 262, 266, 262, 266, 264, 268, 270, 272, 272, 274, 274, 274, 272, 276, 276, 278, 278, 278, 278, 264, 268, 270, 272, 272, 266, 270, 272, 274, 270, 274, 276, 278, 264, 268, 270, 272, 272, 276, 274, 278, 276, 276, 278, 264, 266, 270, 272, 272, 274, 274, 276, 276, 264, 268, 270, 272, 272, 268, 270, 264, 268, 270, 266, 270, 264, 268, 270, 264, 264, 268, 270, 272, 272, 274, 274, 276, 276, 276, 266, 270, 268, 272, 274, 276, 276, 280, 270, 274, 276, 278, 278, 282, 266, 270, 272, 274, 274, 278, 274, 278, 278, 268, 272, 274, 266, 270, 272, 274, 274, 278, 276, 272, 270, 274, 266, 270, 272, 274, 274, 278, 268, 272, 266, 270, 272, 274, 274, 278, 266, 270, 272, 274, 266, 270, 266, 270, 270, 268, 272, 274, 272, 276, 278, 278, 280, 280, 280, 282, 282, 276, 280, 282, 268, 272, 274, 276, 276, 280, 270, 274, 276, 278, 278, 282, 274, 268, 272, 272, 276, 276, 280, 278, 282, 280, 280, 282, 268, 272, 270, 274, 276, 278, 278, 282, 276, 268, 272, 274, 276, 276, 280, 278, 268, 272, 274, 276, 270, 268, 272, 274, 268, 268, 272, 274, 276, 276, 278, 278, 280, 280, 280, 282, 270, 274, 276, 272, 276, 276, 280, 280, 282, 282, 274, 278, 280, 282, 270, 274, 276, 278, 278, 282, 280, 284, 282, 282, 272, 276, 270, 274, 276, 278, 278, 282, 280, 284, 282, 282, 270, 274, 276, 278, 278, 282, 280, 272, 270, 274, 276, 278, 278, 282, 270, 274, 276, 278, 270, 274, 270, 274, 276, 278, 272, 276, 278, 280, 280, 276, 280, 282, 284, 284, 286, 286, 286, 288, 288, 272, 276, 278, 280, 280, 284, 282, 274, 278, 280, 282, 282, 286, 272, 276, 278, 280, 276, 280, 282, 284, 284, 284, 286, 272, 276, 278, 274, 278, 280, 282, 282, 284, 272, 276, 278, 280, 280, 284, 282, 272, 276, 276, 280, 280, 272, 276, 278, 272, 272, 276, 278, 280, 280, 282, 282, 284, 284, 284, 286, 286, 274, 278, 280, 282, 276, 280, 282, 284, 280, 284, 286, 288, 278, 282, 274, 278, 280, 282, 282, 286, 284, 288, 286, 286, 288, 276, 274, 278, 280, 282, 282, 286, 284, 288, 286, 286, 274, 278, 278, 280, 282, 286, 284, 288, 274, 278, 280, 282, 282, 286, 274, 278, 280, 282, 274, 278, 274, 278, 280, 282, 282, 276, 278, 282, 284, 284, 286, 286, 280, 284, 286, 288, 288, 290, 290, 294, 276, 280, 282, 284, 284, 284, 286, 290, 278, 282, 284, 286, 286, 276, 280, 282, 284, 284, 282, 280, 284, 286, 288, 288, 276, 280, 282, 284, 278, 282, 284, 286, 286, 276, 280, 282, 284, 284, 288, 286, 276, 280, 282, 284, 280, 276, 278, 282, 276, 276, 280, 282, 284, 284, 286, 286, 288, 288, 286, 290, 290, 290, 278, 282, 284, 286, 286, 280, 284, 286, 288, 288, 288, 284, 288, 290, 278, 282, 284, 286, 286, 290, 288, 292, 290, 290, 292, 296, 278, 282, 284, 286, 286, 290, 286, 290, 290, 290, 278, 282, 284, 286, 282, 286, 284, 288, 278, 280, 284, 286, 286, 288, 278, 282, 284, 286, 278, 282, 278, 282, 284, 286, 286, 290, 280, 284, 282, 286, 286, 290, 290, 294, 292, 284, 288, 290, 292, 292, 294, 280, 284, 286, 288, 288, 292, 290, 294, 292, 282, 286, 288, 290, 280, 284, 286, 288, 288, 292, 290, 294, 284, 288, 290, 280, 284, 286, 288, 288, 282, 286, 288, 290, 280, 284, 286, 288, 288, 292, 290, 280, 284, 286, 288, 288, 280, 284, 282, 280, 280, 284, 286, 288, 288, 290, 290, 292, 292, 292, 294, 294, 294, 298, 282, 286, 288, 290, 290, 294, 284, 288, 290, 292, 292, 296, 294, 298, 282, 286, 286, 290, 290, 294, 292, 296, 294, 294, 296, 298, 282, 284, 288, 290, 290, 292, 292, 294, 294, 294, 282, 286, 288, 290, 290, 294, 286, 290, 282, 286, 284, 288, 290, 292, 282, 286, 288, 290, 282, 286, 282, 286, 288, 290, 290, 294, 292, 284, 288, 290, 286, 290, 292, 294, 290, 294, 296, 298, 288, 292, 294, 296, 284, 288, 290, 292, 292, 296, 294, 298, 296};




int main(){

	int N;
	cin >> N;
	cout << boxes[N-1];

}
