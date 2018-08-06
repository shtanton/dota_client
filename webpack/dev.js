const path = require("path");
const merge = require("webpack-merge");
const common = require("./common");
const webpack = require("webpack");

module.exports = merge(common, {
	mode: "development",
	devtool: "source-map",
	devServer: {
		contentBase: path.resolve("dist"),
		hot: true,
	},
	plugins: [new webpack.HotModuleReplacementPlugin()],
});
