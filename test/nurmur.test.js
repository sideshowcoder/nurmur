var assert = require("assert")
var nurmur = require("../")


describe("nurmur", function () {
  var SEED = 123

  it("hashes a string with x64 and 128 bit", function (done) {
    nurmur.murmur3_x64_128("abc", SEED, function(err, data) {
      assert.ifError(err)
      assert.ok(data)
      done()
    })
  })

  it("hashes a string x86 and 128 bit", function (done) {
    nurmur.murmur3_x86_128("abc", SEED, function(err, data) {
      assert.ifError(err)
      assert.ok(data)
      done()
    })
  })

  it("hashes a string x86 and 32 bit", function (done) {
    nurmur.murmur3_x86_32("abc", SEED, function(err, data) {
      assert.ifError(err)
      assert.ok(data)
      done()
    })
  })
})
