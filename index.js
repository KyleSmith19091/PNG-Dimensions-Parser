const pngParserModule = require('bindings')('pngParser');
console.log(pngParserModule);
const data = pngParserModule.getImageDimensions("./src/1.png");

