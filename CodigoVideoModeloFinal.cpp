#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main() {
    const char* videoPath = "C:/Users/Juliano/CodigosVSC/ProjetoTpv/test.mp4";
    const char* ffmpegCmd =  "ffprobe -v error -select_streams v:0 -show_entries stream=codec_name -of default=noprint_wrappers=1:nokey=1 test.mp4";


    try {
    /*a forma correta de executar o vídeo com o ffmpeg em uma janela separada usando ffplay é: 
        std::string ffplayCmd = "ffplay -i " + std::string(videoPath);
        int result = system(ffplayCmd.c_str());
        if (result != 0) {
            throw std::runtime_error("Erro ao executar o vídeo.");
        }
    */ 

     /*
     como o meu computador travou por conta de um bug ao executar o ffmpeg, executei o codigo a seguir:
     */
        // execucao direta do video via windows
        std::string filePath = std::string(videoPath).c_str();
        int result = system(filePath.c_str());
        if (result != 0) {
            throw std::runtime_error("Erro ao executar o vídeo.");
        }

        // Imprimir o codec do arquivo de vídeo
        std::string codecCmd = std::string(ffmpegCmd); // + videoPath + " -hide_banner";
        result = system(codecCmd.c_str());
        if (result != 0) {
            throw std::runtime_error("Erro ao obter informações do codec.");
        }
    } catch (const std::exception& e) {
        std::cout << "Exceção: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}