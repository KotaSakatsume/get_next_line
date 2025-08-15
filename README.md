# get_next_line

## 概要

`get_next_line`は、指定されたファイルディスクリプタから1行を読み込むC言語の関数です。

このプロジェクトは、42Tokyoの課題の一つです。

## 特徴

-   ファイルまたは標準入力から1行ずつテキストを読み込みます。
-   複数のファイルディスクリプタを同時に扱うことが可能です。
-   `BUFFER_SIZE`マクロを使用して、読み込みバッファのサイズをコンパイル時に指定できます。

## 関数のプロトタイプ

```c
char *get_next_line(int fd);
```

### パラメータ

-   `int fd`: 読み込み対象のファイルディスクリプタ。

### 戻り値

-   読み込んだ行（改行文字を含む）の文字列へのポインタ。
-   ファイルの終端に達した場合、またはエラーが発生した場合は`NULL`を返します。

## 使い方

1.  リポジトリをクローンします。
    ```bash
    git clone https://github.com/your_username/get_next_line.git
    cd get_next_line
    ```

2.  以下のファイルをプロジェクトに含めます。
    -   `get_next_line.c`
    -   `get_next_line_utils.c`
    -   `get_next_line.h`

3.  テスト用の`main.c`ファイルを作成します。

    ```c
    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main(void)
    {
        int fd;
        char *line;

        // "test.txt" を読み取り専用で開く
        fd = open("test.txt", O_RDONLY);
        if (fd == -1)
        {
            perror("ファイルのオープンに失敗しました");
            return (1);
        }

        // get_next_line を使ってファイルを行ごとに読み込む
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line); // get_next_line が確保したメモリを解放
        }

        close(fd);
        return (0);
    }
    ```

4.  コンパイルして実行します。`BUFFER_SIZE`は任意の値に設定できます。

    ```bash
    # コンパイル
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

    # 実行
    ./gnl
    ```
