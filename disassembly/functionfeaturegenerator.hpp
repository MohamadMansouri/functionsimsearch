#ifndef FUNCTIONFEATUREGENERATOR_HPP
#define FUNCTIONFEATUREGENERATOR_HPP

typedef std::tuple<std::string, std::string, std::string> MnemTuple;
typedef uint64_t address;
class Flowgraph;

// In order to calculate a per-function SimHash, we need something that provides
// graphlets and mnemonic-3-grams to the calculation. This file defines a simple
// interface to do so. Deriving from this interface for whatever disassembly
// infrastructure you are operating on allows de-coupling the disassembler from
// the hash calculation.

class FunctionFeatureGenerator {
public:
  // Subgraph-extraction functions.
  virtual bool HasMoreSubgraphs() const = 0;
  virtual std::pair<Flowgraph*, address> GetNextSubgraph() = 0;
  // Mnemonics-extraction functions.
  virtual bool HasMoreMnemonics() const = 0;
  virtual MnemTuple GetNextMnemTuple() = 0;
  // Immediate values in operands extraction functions.
  virtual bool HasMoreImmediates() const = 0;
  virtual uint64_t GetNextImmediate() = 0;
  // Virtual destructors should be non-abstract.
  virtual ~FunctionFeatureGenerator() {};
};

#endif // FUNCTIONFEATUREGENERATOR_HPP

