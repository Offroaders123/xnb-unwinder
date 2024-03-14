// @ts-check

import { readFile } from "node:fs/promises";

const wasmPath = new URL("./bin/xnb.wasm", import.meta.url);
const wasmBuffer = await readFile(wasmPath);

const wasmMemory = new WebAssembly.Memory({
  initial: 0x10000
});

const wasmModule = await WebAssembly.instantiate(wasmBuffer, {
  js: { mem: wasmMemory }
});
console.log(wasmModule);