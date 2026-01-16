std::ofstream outputFile(filename); // 创建输出文件流

if (!outputFile.is_open()) {
    std::cout << "错误：无法创建或打开文件 " << filename << "！" << std::endl;
    return;
}

std::ifstream inputFile(filename); // 创建输入文件流

if (!inputFile.is_open()) {
    std::cout << "文件 " << filename << " 不存在或无法打开，将创建新文件。" << std::endl;
    return;
}