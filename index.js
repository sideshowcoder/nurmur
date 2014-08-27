var murmur3 = require("./build/Release/murmur3")

/* murmur3 defines 3 functions
 *
 * murmur3_x86_32   32  Bit version optimized for x86
 * murmur3_x86_128  128 Bit version optimized for x86
 * murmur3_x64_128  128 Bit version optimized for x64
 *
 * Example:
 *
 * var nurmur = require("nurmur")
 *
 * nurmur.murmur3_x64_128(data, seed, function(err, hashedData) {
 *   if (err) return new Error(err)
 *   console.log(hashedData)
 * })
 *
 */

module.exports = murmur3
