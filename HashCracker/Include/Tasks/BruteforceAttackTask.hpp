#pragma once

#include "Tasks/AttackTask.hpp"

namespace HonoursProject
{
    class Charset;

    class HASHCRACK_PUBLIC BruteforceAttackTask : public AttackTask
    {
    public:

        virtual ~BruteforceAttackTask();

        virtual std::string run(std::shared_ptr<HashCracker> hash_cracker) override;

        virtual void transfer(std::shared_ptr<BaseTask> task) override;

        virtual void setBatchSize(std::uint32_t batch_size) override;

        virtual void setBatchOffset(std::uint64_t batch_offset) override;

        virtual void setInnerLoopStep(std::uint32_t inner_loop_step) override;

    private:

        std::vector<Charset> charsets;

        std::shared_ptr<Kernel> kernel_gen_word_prefix;

        std::shared_ptr<Kernel> kernel_gen_word_suffix;

        virtual void preKernelExecute(std::uint32_t inner_loop_left, std::uint32_t inner_loop_pos) override;

    };
}
