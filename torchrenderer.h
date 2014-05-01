#ifndef TORCHRENDERER_H
#define TORCHRENDERER_H

#include "blockrenderer.h"

class TorchRenderer : public DumbBlockRenderer
{
public:
    virtual void renderSpecialBlock(const BLOCK_WDATA block, GLFix x, GLFix y, GLFix z, Chunk &c) override;
    virtual int indicesNormalBlock(const BLOCK_WDATA, int, int, int, const BLOCK_SIDE, Chunk &) override { return 0; }
    virtual void geometryNormalBlock(const BLOCK_WDATA, int /*local_x*/, int /*local_y*/, int /*local_z*/, const BLOCK_SIDE /*side*/, Chunk &/*c*/) override {};
    virtual bool isOpaque(const BLOCK_WDATA /*block*/) override { return false; }
    virtual bool isObstacle(const BLOCK_WDATA /*block*/) override { return false; }
    virtual bool isOriented(const BLOCK_WDATA /*block*/) override { return true; }
    virtual bool isFullyOriented(const BLOCK_WDATA /*block*/) override { return true; }

    virtual bool isBlockShaped(const BLOCK_WDATA /*block*/) override { return false; }
    virtual AABB getAABB(const BLOCK_WDATA block, GLFix x, GLFix y, GLFix z) override;

    virtual void drawPreview(const BLOCK_WDATA block, TEXTURE &dest, int x, int y) override;

    virtual const char* getName(const BLOCK_WDATA) override;

protected:
    static constexpr GLFix torch_height = BLOCK_SIZE / 16 * 9;
    static constexpr GLFix torch_width = BLOCK_SIZE / 16 * 14;
};

#endif // TORCHRENDERER_H
