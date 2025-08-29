# BMP to Grayscale / Grayscale to Sobel filter Convert Software
## Origin
<img width="200" height="200" alt="brainct_001" src="https://github.com/user-attachments/assets/f5ba7d69-bd7c-41cd-8f02-a3057cea2617" />
<img width="200" height="200" alt="output_grayscale" src="https://github.com/user-attachments/assets/1ba170b4-ef9c-4b95-9b94-f3ab6447f288" />
<img width="200" height="200" alt="output_edge" src="https://github.com/user-attachments/assets/89164f39-d080-4f3c-9885-9b015d7eb700" />

## 📑 문서 관리 정보

-   **문서 ID**: BMP-DO178C-001  
-   **버전**: 1.0  
-   **날짜**: 2025-08-28  
-   **설계 보증 레벨**: DAL-D  
-   **시스템**: 항공 디스플레이 처리 장치

------------------------------------------------------------------------

## 1. 소프트웨어 인증 계획서 (PSAC)

### 1.1 소프트웨어 개요

-   **항목**: BMP 그레이스케일 변환기  
-   **기능**: 항공 디스플레이 시스템용 24비트 컬러 BMP 이미지를 8비트
    그레이스케일로 변환  
-   **중요도 레벨**: DAL-D (경미한 고장 상황)

### 1.2 소프트웨어 생명주기 프로세스

-   계획 수립 프로세스  
-   소프트웨어 개발 프로세스  
-   소프트웨어 검증 프로세스  
-   소프트웨어 형상관리 프로세스  
-   소프트웨어 품질보증 프로세스

### 1.3 소프트웨어 생명주기 데이터

제출 문서: - PSAC (소프트웨어 인증 계획서)  
- SRS (소프트웨어 요구사항 표준)  
- SDS (소프트웨어 설계 표준)  
- SCS (소프트웨어 코드 표준)  
- SVP (소프트웨어 검증 계획)  
- SCMP (소프트웨어 형상관리 계획)

------------------------------------------------------------------------

## 2. 소프트웨어 요구사항 표준 (SRS)

### 2.1 상위레벨 요구사항 (HLR)

-   **HLR-001: 이미지 형식 검증**
    -   입력 파일이 24비트 BMP 형식인지 검증  
    -   이미지 크기가 630×630 픽셀인지 확인  
    -   잘못된 형식은 오류 메시지와 함께 거부

            // 입력 파일 열기
            if (fopen_s(&inFile, inputFile, "rb") != 0 || inFile == NULL) {
                printf("입력 파일을 열 수 없습니다: %s\n", inputFile);
                return 1;
            }
        
            // BMP 헤더 읽기
            BMPFileHeader fileHeader;
            BMPInfoHeader infoHeader;
        
            fread(&fileHeader, sizeof(BMPFileHeader), 1, inFile);
            fread(&infoHeader, sizeof(BMPInfoHeader), 1, inFile);
        
            // BMP 파일 형식 검증
            if (fileHeader.type != 0x4D42) { // "BM"
                printf("유효하지 않은 BMP 파일입니다.\n");
                fclose(inFile);
                return 1;
            }
        
            if (infoHeader.bitCount != 24) {
                printf("24비트 BMP 파일이 아닙니다. (현재: %d비트)\n", infoHeader.bitCount);
                fclose(inFile);
                return 1;
            }
        
            if (infoHeader.width != IMAGE_WIDTH || infoHeader.height != IMAGE_HEIGHT) {
                printf("이미지 크기가 %dx%d가 아닙니다. (현재: %dx%d)\n",
                    IMAGE_WIDTH, IMAGE_HEIGHT, infoHeader.width, infoHeader.height);
                fclose(inFile);
                return 1;
            }
 
-   **HLR-002: 색공간 변환**
    -   휘도 변환 공식 적용:

            Y = 0.299R + 0.587G + 0.114B
        
            // RGB를 그레이스케일로 변환하는 함수
            uint8_t rgbToGrayscale(RGB pixel) {
                // 표준 luminance 공식: Y = 0.299*R + 0.587*G + 0.114*B
                return (uint8_t)(0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue);
            }

            // 변환 루프
            uint8_t* grayscaleData = (uint8_t*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
            for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
                grayscaleData[i] = rgbToGrayscale(imageData[i]);
            }

    -   픽셀의 공간적 관계 유지  

    -   출력 값은 0–255 범위


-   **HLR-003: 출력 파일 생성**
    -   8비트 그레이스케일 BMP 파일 생성  
    -   256색 그레이스케일 팔레트 포함  
    -   BMP 표준 준수

            // 8비트 그레이스케일 BMP 헤더 설정
            int newPadding = (4 - (IMAGE_WIDTH % 4)) % 4;
            int newRowSize = IMAGE_WIDTH + newPadding;
            int paletteSize = 256 * 4; // 256색 팔레트 (각 항목은 4바이트)
        
            BMPFileHeader newFileHeader = fileHeader;
            BMPInfoHeader newInfoHeader = infoHeader;
        
            newFileHeader.size = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + paletteSize + (newRowSize * IMAGE_HEIGHT);
            newFileHeader.offset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + paletteSize;
        
            newInfoHeader.bitCount = 8;
            newInfoHeader.sizeImage = newRowSize * IMAGE_HEIGHT;
            newInfoHeader.clrUsed = 256;
            newInfoHeader.clrImportant = 256;
        
        
        	// 그레이스케일 BMP 헤더 쓰기
        	fwrite(&newFileHeader, sizeof(BMPFileHeader), 1, outFile);
        	fwrite(&newInfoHeader, sizeof(BMPInfoHeader), 1, outFile);
        
            // 엣지 검출 BMP 헤더는 그레이스케일과 동일
            fwrite(&newFileHeader, sizeof(BMPFileHeader), 1, edgeOutFile);
            fwrite(&newInfoHeader, sizeof(BMPInfoHeader), 1, edgeOutFile);
        
            // 그레이스케일 팔레트 생성 및 쓰기
            for (int i = 0; i < 256; i++) {
                uint8_t color[4] = { i, i, i, 0 }; // Blue, Green, Red, Reserved
                fwrite(color, 4, 1, outFile);
            }
        
            // 엣지 팔레트 쓰기
            for (int i = 0; i < 256; i++) {
                uint8_t color[4] = { i, i, i, 0 };
                fwrite(color, 4, 1, edgeOutFile);
            }
        
        
            // 그레이스케일 이미지 데이터 쓰기 (아래쪽부터)
            uint8_t paddingBytes[4] = { 0 };
        
            for (int y = IMAGE_HEIGHT - 1; y >= 0; y--) {
                for (int x = 0; x < IMAGE_WIDTH; x++) {
                    fwrite(&grayscaleData[y * IMAGE_WIDTH + x], 1, 1, outFile);
                }
                // 패딩 쓰기
                if (newPadding > 0) {
                    fwrite(paddingBytes, newPadding, 1, outFile);
                }
            }
        
            fclose(outFile);
        
            // 엣지 데이터 쓰기
            for (int y = IMAGE_HEIGHT - 1; y >= 0; y--) {
                for (int x = 0; x < IMAGE_WIDTH; x++) {
                    fwrite(&edgeData[y * IMAGE_WIDTH + x], 1, 1, edgeOutFile);
                }
                if (newPadding > 0) {
                    fwrite(paddingBytes, newPadding, 1, edgeOutFile);
                }
            }
            fclose(edgeOutFile);
        
            // MEM 파일에 그레이스케일 데이터를 16진수로 쓰기
            // 각 픽셀값을 2자리 16진수로 변환하고 줄바꿈(0x0D 0x0A)으로 구분
            for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
                fprintf(memOutFile, "%02X\r\n", grayscaleData[i]);
            }
        
            fclose(memOutFile);
        

-   **HLR-004: 메모리 관리**
    -   동적 메모리 할당 실패 감지 및 처리  
    -   모든 메모리 적절히 해제  
    -   메모리 누수 방지

            // 이미지 데이터 메모리 할당
            RGB* imageData = (RGB*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(RGB)); //malloc : 괄호 안에 있는 데이터만큼 메모리 할당
            if (imageData == NULL) {
                printf("메모리 할당 실패\n");
                fclose(inFile);
                return 1;
            }
            uint8_t* grayscaleData = (uint8_t*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
            if (grayscaleData == NULL) {
                printf("메모리 할당 실패\n");
                free(imageData);
                return 1;
            }
            free(imageData);
            free(grayscaleData);
            free(edgeData);   


-   **HLR-005: 오류 처리**
    -   파일 I/O 오류 감지 및 보고  
    -   비정상 종료 시 리소스 정리  
    -   명확한 오류 메시지 제공

            // 입력 파일 열기
            if (fopen_s(&inFile, inputFile, "rb") != 0 || inFile == NULL) {
                printf("입력 파일을 열 수 없습니다: %s\n", inputFile);
                return 1;
            }

            // BMP 파일 형식 검증
            if (fileHeader.type != 0x4D42) { // "BM"
                printf("유효하지 않은 BMP 파일입니다.\n");
                fclose(inFile);
                return 1;
            }
        
            if (infoHeader.bitCount != 24) {
                printf("24비트 BMP 파일이 아닙니다. (현재: %d비트)\n", infoHeader.bitCount);
                fclose(inFile);
                return 1;
            }
        
            if (infoHeader.width != IMAGE_WIDTH || infoHeader.height != IMAGE_HEIGHT) {
                printf("이미지 크기가 %dx%d가 아닙니다. (현재: %dx%d)\n",
                    IMAGE_WIDTH, IMAGE_HEIGHT, infoHeader.width, infoHeader.height);
                fclose(inFile);
                return 1;
            }
        
            // 이미지 데이터 메모리 할당
            RGB* imageData = (RGB*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(RGB)); //malloc : 괄호 안에 있는 데이터만큼 메모리 할당
            if (imageData == NULL) {
                printf("메모리 할당 실패\n");
                fclose(inFile);
                return 1;
            }
        
            // 그레이스케일 변환
            uint8_t* grayscaleData = (uint8_t*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
            if (grayscaleData == NULL) {
                printf("메모리 할당 실패\n");
                free(imageData);
                return 1;
            }
        
            for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
                grayscaleData[i] = rgbToGrayscale(imageData[i]);
            }
        
            // 엣지 검출을 위한 메모리 할당 및 처리 (새로 추가)
            uint8_t* edgeData = (uint8_t*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
            if (edgeData == NULL) {
                printf("엣지 데이터 메모리 할당 실패\n");
                free(imageData);
                free(grayscaleData);
                return 1;
            }
        
            findEdges(grayscaleData, edgeData, IMAGE_WIDTH, IMAGE_HEIGHT);
        
            // 출력 파일 생성
            if (fopen_s(&outFile, outputFile, "wb") != 0 || outFile == NULL) {
                printf("출력 파일을 생성할 수 없습니다: %s\n", outputFile);
                free(imageData);
                free(grayscaleData);
                return 1;
            }
        
            // MEM 파일 생성
            if (fopen_s(&memOutFile, memFile, "w") != 0 || memOutFile == NULL) {
                printf("MEM 파일을 생성할 수 없습니다: %s\n", memFile);
                free(imageData);
                free(grayscaleData);
                return 1;
            }
        
            // 엣지 검출 결과를 BMP로 저장
            if (fopen_s(&edgeOutFile, edgeFile, "wb") != 0 || edgeOutFile == NULL) {
                printf("엣지 출력 파일을 생성할 수 없습니다: %s\n", edgeFile);
                free(imageData);
                free(grayscaleData);
                free(edgeData);
                return 1;
            }

### 2.2 저수준 요구사항 (LLR)

-   **LLR-001: BMP 헤더 검증**
    -   시그니처 = `0x4D42 ("BM")`  
    -   `bitCount` = 24  
    -   width, height = 630

            #pragma pack(push, 1)
            typedef struct {
                uint16_t type;        // 파일 형식 (BM)
                uint32_t size;        // 파일 크기
                uint16_t reserved1;   // 예약된 필드
                uint16_t reserved2;   // 예약된 필드
                uint32_t offset;      // 이미지 데이터 시작 위치
            } BMPFileHeader;
            
            typedef struct {
                uint32_t size;        // 헤더 크기
                int32_t  width;        // 이미지 너비
                int32_t  height;       // 이미지 높이
                uint16_t planes;      // 색상 평면 수
                uint16_t bitCount;    // 픽셀당 비트 수
                uint32_t compression; // 압축 형식
                uint32_t sizeImage;   // 이미지 데이터 크기
                int32_t  xPelsPerMeter;// 수평 해상도
                int32_t  yPelsPerMeter;// 수직 해상도
                int32_t  clrUsed;      // 사용된 색상 수
                uint32_t clrImportant;// 중요한 색상 수
            } BMPInfoHeader;
            
            typedef struct {
                uint8_t blue;
                uint8_t green;
                uint8_t red;
            } RGB;
            #pragma pack(pop)


-   **LLR-002: 픽셀 데이터 읽기**
    -   하단부터 상단 순서로 읽기  
    -   각 행의 패딩 처리  
    -   RGB 구조체 저장

            int padding = (4 - ((IMAGE_WIDTH * 3) % 4)) % 4;
            fseek(inFile, fileHeader.offset, SEEK_SET); // fseek : 파일 포인터를 offset 바이트만큼 이동, SEEK_SET : 파일의 시작 위치
            for (int y = IMAGE_HEIGHT - 1; y >= 0; y--) {
                for (int x = 0; x < IMAGE_WIDTH; x++) {
                    fread(&imageData[y * IMAGE_WIDTH + x], sizeof(RGB), 1, inFile);
                }
                // 패딩 건너뛰기
                fseek(inFile, padding, SEEK_CUR);
            }

-   **LLR-003: 그레이스케일 변환 알고리즘**
    -   휘도 공식 적용 후 `uint8_t`로 변환  
    -   별도 배열에 저장

            > HLR‑002의 변환 루프 및 `rgbToGrayscale()` 참조.

-   **LLR-004: 출력 BMP 생성**
    -   8비트 BMP 헤더 생성  
    -   256색 그레이스케일 팔레트 작성  
    -   데이터 하단부터 상단 순으로 출력

            > HLR‑003의 팔레트·쓰기 루프 참조.

------------------------------------------------------------------------

## 3. 소프트웨어 설계 표준 (SDS)

### 3.1 아키텍처 설계

    BMP_Processor
    ├── File_Handler
    │   ├── Input_Validator
    │   └── Output_Generator
    ├── Image_Processor
    │   ├── Color_Converter
    │   └── Memory_Manager
    └── Error_Handler

### 3.2 상세 설계

**구조체 정의**  
- `BMPFileHeader` – BMP 파일 헤더  
- `BMPInfoHeader` – BMP 정보 헤더  
- `RGB` – 24비트 RGB 픽셀

**주요 함수**  
- `main()` – 메인 프로세스 제어  
- `rgbToGrayscale()` – 색공간 변환  
- 파일 I/O 처리 루틴  
- 메모리 관리 루틴

            //데이터 타입
            typedef struct {
                uint8_t blue;
                uint8_t green;
                uint8_t red;
            } RGB;
            
            // 변환 코어
            uint8_t rgbToGrayscale(RGB pixel);
            
            int sobelX[3][3] = {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1}
            };
            
            int sobelY[3][3] = {
                {-1, -2, -1},
                { 0,  0,  0},
                { 1,  2,  1}
            };
            unsigned char getPixel(unsigned char* image, int width, int height, int x, int y)
            void findEdges(unsigned char* input, unsigned char* output, int width, int height)

### 3.3 인터페이스 설계

-   **입력**:
    -   파일명: `brainct_001.bmp`  
    -   형식: 24비트 BMP, 630×630
-   **출력**:
    -   파일명: `output_grayscale.bmp`  
    -   형식: 8비트 그레이스케일 BMP  
    -   팔레트: 256색

            const char* inputFile = "brainct_001.bmp";
            const char* outputFile = "output_grayscale.bmp";
            const char* edgeFile = "output_edge.bmp";  // 엣지 검출 BMP 파일 추가
            const char* memFile = "output_image.mem";  // MEM 파일 이름 추가

------------------------------------------------------------------------

## 4. 소프트웨어 코드 표준 (SCS)

### 4.1 코딩 규칙

-   **명명 규칙**
    -   구조체: `PascalCase`  
    -   함수: `camelCase`  
    -   변수: `camelCase`  
    -   상수: `UPPER_CASE`
-   **코드 스타일**
    -   들여쓰기: 4칸 스페이스  
    -   중괄호: K&R 스타일  
    -   한 줄당 하나의 명령문  
    -   충분한 주석 작성

### 4.2 품질 기준

-   가독성: 명확한 변수명, 주석 포함  
-   유지보수성: 모듈화 구조, 오류 처리, 메모리 관리 준수

            typedef struct {
                uint16_t type;        // 파일 형식 (BM)
                uint32_t size;        // 파일 크기
                uint16_t reserved1;   // 예약된 필드
                uint16_t reserved2;   // 예약된 필드
                uint32_t offset;      // 이미지 데이터 시작 위치
            } BMPFileHeader;

            typedef struct {
                uint32_t size;        // 헤더 크기
                int32_t  width;        // 이미지 너비
                int32_t  height;       // 이미지 높이
                uint16_t planes;      // 색상 평면 수
                uint16_t bitCount;    // 픽셀당 비트 수
                uint32_t compression; // 압축 형식
                uint32_t sizeImage;   // 이미지 데이터 크기
                int32_t  xPelsPerMeter;// 수평 해상도
                int32_t  yPelsPerMeter;// 수직 해상도
                int32_t  clrUsed;      // 사용된 색상 수
                uint32_t clrImportant;// 중요한 색상 수
            } BMPInfoHeader;
            
            typedef struct {
                uint8_t blue;
                uint8_t green;
                uint8_t red;
            } RGB;

------------------------------------------------------------------------

## 5. 소프트웨어 검증 계획 (SVP)

### 5.1 검증 목표

-   요구사항의 올바른 구현 확인  
-   항공 안전 기준 충족 여부 검증  
-   오류 조건 동작 확인

### 5.2 검증 방법

-   **정적 분석**: 코드 리뷰, MISRA-C 규칙, 정적 분석 도구  
-   **동적 테스트**: 단위, 통합, 시스템 테스트

            printf("입력 파일 정보:\n");
            printf("- 크기: %dx%d\n", infoHeader.width, infoHeader.height);
            printf("- 비트 수: %d\n", infoHeader.bitCount);
            printf("- 파일 크기: %d bytes\n", fileHeader.size);
            printf("\n변환 완료!\n");
            printf("출력 파일: %s\n", outputFile);
            printf("그레이스케일 8비트 BMP로 저장되었습니다.\n");
            printf("엣지 검출 BMP 파일: %s\n", edgeFile);        // 엣지 BMP 파일 메시지 추가
            printf("그레이스케일 MEM 파일: %s\n", memFile);  // MEM 파일 생성 완료 메시지 추가

### 5.3 테스트 케이스

-   **TC-001**: 정상 입력 처리 → 성공적인 변환  
-   **TC-002**: 잘못된 파일 형식 → 오류 메시지  
-   **TC-003**: 잘못된 이미지 크기 → 오류 메시지  
-   **TC-004**: 메모리 부족 상황 → 적절한 오류 처리  
-   **TC-005**: 파일 I/O 오류 → I/O 오류 메시지

### 5.4 커버리지 기준

-   명령문 커버리지: 100%  
-   분기 커버리지: 100%  
-   MC/DC: 해당 없음 (DAL-D)

------------------------------------------------------------------------

## 6. 소프트웨어 형상관리 계획 (SCMP)

### 6.1 목표

-   생명주기 동안 변경사항 추적  
-   베이스라인 관리 및 버전 제어  
-   변경 요청 및 승인 절차 관리

### 6.2 형상 식별

-   소스 코드 파일  
-   실행 파일  
-   문서 자료  
-   테스트 케이스 및 결과

### 6.3 변경 관리

1.  변경 요청서 작성  
2.  기술 검토  
3.  영향 분석  
4.  승인/거부 결정  
5.  구현 및 검증  
6.  형상 업데이트

        /bmp_gray/
          ├─ main.c                  // 본 소스
          ├─ brainct_001.bmp         // 테스트 입력
          ├─ output_grayscale.bmp    // 결과(8bit)
          ├─ output_edge.bmp         // (확장) 소벨 엣지
          └─ output_image.mem        // (확장) Gray MEM dump

------------------------------------------------------------------------

## 7. 추적성 매트릭스

| 요구사항 ID | 설계 요소        | 코드 / 함수        | 테스트 케이스  |
|-------------|------------------|--------------------|----------------|
| HLR-001     | File_Validator   | fread(), 헤더 검증 | TC-001,002,003 |
| HLR-002     | Color_Converter  | rgbToGrayscale()   | TC-001         |
| HLR-003     | Output_Generator | BMP 생성 루틴      | TC-001         |
| HLR-004     | Memory_Manager   | malloc(), free()   | TC-004         |
| HLR-005     | Error_Handler    | 오류 처리 루틴     | TC-002\~TC-005 |

            | 요구사항 ID | 구현 코드(핵심 지점) |
            | --- | --- |
            | HLR‑001 | 헤더 검증 블록(`fileHeader.type`, `bitCount`, `width/height`), 패딩 계산 |
            | HLR‑002 | `rgbToGrayscale()`, 그레이스케일 변환 루프 |
            | HLR‑003 | 새 헤더/팔레트 생성 및 쓰기, 바텀업 픽셀 쓰기 |
            | HLR‑004 | `malloc()` 실패 처리 및 `free()` 호출 |
            | HLR‑005 | `fopen_s()` 실패 분기·메시지, 자원 정리 패턴 |

------------------------------------------------------------------------

## 8. 인증 결론

본 BMP 그레이스케일 변환 소프트웨어는 **DO-178C DAL-D** 요구사항을
충족하도록 설계 및 구현되었습니다.  
모든 필수 문서가 준비되었으며, 계획된 검증 활동을 통해 소프트웨어의
**안전성과 신뢰성**이 입증될 것입니다.

**승인:**  
- 개발팀장: `________________`  
- 품질보증 관리자: `________________`  
- 인증 담당자: `________________`  
- 날짜: 2025-08-28





