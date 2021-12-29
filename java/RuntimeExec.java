/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-12-29 10:11:54
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-29 10:15:12
 */

import java.io.ByteArrayOutputStream;
import java.io.InputStream;

public class RuntimeExec {
    public static void main(String[] args) throws Exception {
        InputStream in = Runtime.getRuntime().exec("ipconfig").getInputStream();
        byte[] bcache = new byte[1024];
        int readSize = 0;
        ByteArrayOutputStream infoStream = new ByteArrayOutputStream();
        while ((readSize = in.read(bcache)) > 0) {
            infoStream.write(bcache, 0, readSize);
        }
        System.out.println(infoStream.toString());
    }
}
