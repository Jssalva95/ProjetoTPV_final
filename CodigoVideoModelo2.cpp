#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main() {
    const char* videoPath = "C:/Users/Juliano/CodigosVSC/ProjetoTpv/test.mp4";
    const char* ffmpegCmd = "ffprobe -v error -select_streams v:0 -show_entries stream=codec_name -of default=noprint_wrappers=1:nokey=1 test.mp4";

    // Construir o comando completo para obter as informações do codec
    std::string command = std::string(ffmpegCmd); // + videoPath;

    // Executar o comando e redirecionar a saída para o console
    int result = system(command.c_str());
    if (result != 0) {
        std::cout << "Erro ao obter informações do codec." << std::endl;
        return -1;
    }
    /*a forma correta de executar o vídeo com o ffmpeg em uma janela separada usando ffplay é: 
        std::string ffplayCmd = "ffplay -i " + std::string(videoPath);
        result = system(ffplayCmd.c_str()); 
    */ 
     /*
     caso no seu computador trave para executar o ffmpeg execute o codigo a seguir:
     */
    std::string filePath = std::string(videoPath).c_str();
    result = system(filePath.c_str());
    if (result != 0) {
        std::cout << "Erro ao executar o vídeo." << std::endl;
        return -1;
    }

    return 0;
}

