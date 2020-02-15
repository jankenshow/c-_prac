#define __CL_ENABLE_EXCEPTIONS
#include <OpenCL/cl.hpp>
#include <iostream>

// 演算用プロセッサで実行するコードをOpenCL C言語のソースで記述しchar* で参照する
// 通常は別ファイルで記述して、そのファイルを読み込んでchar* で参照する
const char* helloStr = "__kernel void hello(void){}";

int main() {
    cl_int err = CL_SUCCESS;
    try {
        // OpenCLが実行できるプラットフォームの一覧を取得
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);
        // プラットフォームが見つからなければ、エラー出力
        if (platforms.size() == 0) {
            std::cerr << "Platform size 0" << std::endl;
            return -1;
        }
    
        // 先に特定したプラットフォーム上での実行環境OpenCLコンテクストを作成し、使用したいデバイス種類を指定する
        cl_context_properties properties[] = {
            CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[0])(), 0
        };
        cl::Context context(CL_DEVICE_TYPE_GPU, properties);
        // CL_DEVICE_TYPE_CPU - ホストCPUをデバイスとして指定
        // CL_DEVICE_TYPE_GPU - GPUをデバイスとして指定
        // CL_DEVICE_TYPE_DEFAULT - プラットフォームの標準デバイスを指定

        // デバイスの指定
        std::vector<cl::Device> devices = context.getInfo<CL_CONTEXT_DEVICES>();

        // OpenCLデバイスで実行するプログラムの作成
        // プログラム（ソースコード）を文字列（char*）で参照し、実行するコンテキストと合わせてプログラムオブジェクトを生成し、コンパイル
        cl::Program::Sources source(1, std::make_pair(helloStr, strlen(helloStr)));
        cl::Program program = cl::Program(context, source);
        program.build(devices);

        // カーネルの作成 (1つのカーネルは、１つの関数に対応します。第2引数はカーネル関数名を指定)
        cl::Kernel kernel(program, "hello", &err);

        cl::Event event;
        // アプリケーション側からデバイスに制御コマンドを送るために使用するコマンドキューの作成
        cl::CommandQueue queue(context, devices[0], 0, &err);

        // カーネルの実行
        queue.enqueueNDRangeKernel(
            kernel, cl::NullRange, cl::NDRange(4, 4), cl::NullRange, NULL, &event
        );
        event.wait();
    } catch (cl::Error err) {
        std::cerr << "ERROR: " << err.what() << "(" << err.err() << ")" << std::endl;
    }
    return EXIT_SUCCESS;
}
